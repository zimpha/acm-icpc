#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int list[52],list_num;
int pile[7][52],pile_num[7];
int count,freq;
int save[8][52],tmp[8][52],save_num[8],count_temp;

void put_card(int i);
void record();
int draw();
void re();
void put_card_draw(int i);

main()
{
    int i,j,k,n;
    //freopen("in.txt","r",stdin);
    while(1)
    {
        for(i=0;i<52;i++)  //初始化排堆
            list[i]=0;
        for(i=0;i<7;i++)  //初始化放牌的地方
            for(j=0;j<52;j++)
                pile[i][j]=0;
        scanf(" %d",&pile[0][0]);
        tmp[0][0]=pile[0][0];
        if(pile[0][0]==0)   break;
        for(i=1;i<7;i++)  //先發前面14張牌
        {
            scanf(" %d",&pile[i][0]);
            tmp[i][0]=pile[i][0];
        }
        for(i=0;i<7;i++)
        {
            scanf(" %d",&pile[i][1]);
            tmp[i][1]=pile[i][1];
        }
        for(i=0;i<38;i++)
        {
            scanf(" %d",&list[i]);
            tmp[7][i]=list[i];
        }
        for(i=0;i<7;i++)
            pile_num[i]=2;
        list_num=38;
        count=14;
       
        int ans;
        for(i=0;i<=7;i++)
        {
            if(i==7)    i=0;
            if(pile_num[i]==0)  continue;   //表示那疊拿光了
            put_card(i);
            if(list_num==52)
            {
                printf("Win : %d\n",count);
                break;
            }
            else if(list_num==0)
            {
                printf("Loss: %d\n",count);
                break;
            }
            else if(draw())
            {
                freq=count-count_temp;
                re();
                printf("Draw: %d\n",count);
                break;
            }
            if(count==2 || count==4 || count==8 || count==16 || count==32 || count==64 || count==128 || count==256 || count==512 || count==1024 || count==2048)
            {
                count_temp=count;
                record();
            }
        }
       
    }
    //system("PAUSE");
    //getch();
}
void put_card(int i)
{
    int j,k;
    count++;
    pile[i][pile_num[i]]=list[0];
    pile_num[i]++;
    list_num--;
    for(j=0;j<list_num;j++)
        list[j]=list[j+1];  //把排往前補齊
    while(pile_num[i]>=3)
    {
        if((pile[i][0]+pile[i][1]+pile[i][pile_num[i]-1])%10==0)  //第一種情況
        {
            list[list_num++]=pile[i][0];
            list[list_num++]=pile[i][1];
            list[list_num++]=pile[i][pile_num[i]-1];
            pile_num[i]=pile_num[i]-3;
            for(j=0;j<pile_num[i];j++)
                pile[i][j]=pile[i][j+2];  //把牌堆往前補進
        }
        else if((pile[i][0]+pile[i][pile_num[i]-2]+pile[i][pile_num[i]-1])%10==0)  //第二種
        {
            list[list_num++]=pile[i][0];
            list[list_num++]=pile[i][pile_num[i]-2];
            list[list_num++]=pile[i][pile_num[i]-1];
            pile_num[i]=pile_num[i]-3;
            for(j=0;j<pile_num[i];j++)
                pile[i][j]=pile[i][j+1];  //把牌堆往前補進
        }
        else if((pile[i][pile_num[i]-3]+pile[i][pile_num[i]-2]+pile[i][pile_num[i]-1])%10==0)  //第三種
        {
            list[list_num++]=pile[i][pile_num[i]-3];
            list[list_num++]=pile[i][pile_num[i]-2];
            list[list_num++]=pile[i][pile_num[i]-1];
            pile_num[i]=pile_num[i]-3;
            //for(j=0;j<pile_num[i];j++)
                //pile[i][j]=pile[i][j+1];  //把牌堆往前補進
        }
        else    break;
    }
}
void record()
{
    int i,j;
    for(i=0;i<7;i++)
    {
        save_num[i]=pile_num[i];
        for(j=0;j<pile_num[i];j++)
            save[i][j]=pile[i][j];
    }
    save_num[7]=list_num;
    for(i=0;i<list_num;i++)
        save[7][i]=list[i];
}
int draw()
{
    int i,j,k;
    for(i=0;i<7;i++)
    {
        if(save_num[i]!=pile_num[i])
            return 0;
        for(j=0;j<pile_num[i];j++)
            if(save[i][j]!=pile[i][j])
                return 0;
    }
    if(save_num[7]!=list_num)
        return 0;
    for(i=0;i<list_num;i++)
        if(save[7][i]!=list[i])
            return 0;
    return 1;
}
void re()
{
    int i,j,k;
    count=14;
    for(i=0;i<7;i++)
    {   //從心把值都回復到14張的時候
        pile_num[i] = 2;
        save_num[i] = 2;
        for(j=0;j<2;j++)
        {
            pile[i][j]=tmp[i][j];
            save[i][j]=tmp[i][j];
        }
    }
    list_num=38;
    save_num[7]=list_num;
    for(i=0;i<list_num;i++)
    {
        list[i]=tmp[7][i];
        save[7][i]=tmp[7][i];
    }
    for(k=1,i=0;k<=freq;k++)  //開始重複做main的動作
    {
        if(i>=7)    i=0;
        while(pile_num[i]==0)
        {
            i++;
            if(i>=7)    i=0;
        }
        put_card(i++);
    }
    for(j=0;draw()==0;)
    {
        if(i>=7)    i=0;
        if(j>=7)    j=0;
        while(pile_num[i]==0)
        {
            i++;
            if(i>=7)    i=0;
        }
        put_card(i++);
        while(save_num[j]==0)
        {
            j++;
            if(j>=7)    j=0;
        }
        put_card_draw(j++);
        //j++;
    }
}
void put_card_draw(int i)
{
    int j;
    save[i][save_num[i]++]=save[7][0];
    save_num[7]--;
    for(j=0;j<save_num[7];j++)
        save[7][j]=save[7][j+1];
    while(save_num[i]>=3)
    {
        if((save[i][0]+save[i][1]+save[i][save_num[i]-1])%10==0)  //第一種情況
        {
            save[7][save_num[7]++]=save[i][0];
            save[7][save_num[7]++]=save[i][1];
            save[7][save_num[7]++]=save[i][save_num[i]-1];
            save_num[i]=save_num[i]-3;
            for(j=0;j<save_num[i];j++)
                save[i][j]=save[i][j+2];  //把牌堆往前補進
        }
        else if((save[i][0]+save[i][save_num[i]-2]+save[i][save_num[i]-1])%10==0)  //第一種情況
        {
            save[7][save_num[7]++]=save[i][0];
            save[7][save_num[7]++]=save[i][save_num[i]-2];
            save[7][save_num[7]++]=save[i][save_num[i]-1];
            save_num[i]=save_num[i]-3;
            for(j=0;j<save_num[i];j++)
                save[i][j]=save[i][j+1];  //把牌堆往前補進
        }
        else if((save[i][save_num[i]-3]+save[i][save_num[i]-2]+save[i][save_num[i]-1])%10==0)  //第一種情況
        {
            save[7][save_num[7]++]=save[i][save_num[i]-3];
            save[7][save_num[7]++]=save[i][save_num[i]-2];
            save[7][save_num[7]++]=save[i][save_num[i]-1];
            save_num[i]=save_num[i]-3;
            //for(j=0;j<save_num[i];j++)
              //  save[i][j]=save[i][j+1];  //把牌堆往前補進
        }
        else    break;
    }
}
