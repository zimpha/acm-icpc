#include<stdio.h>  
#include<string.h> 

int Size; 
char array[100][61]; 
int longest=0; 

void swap(int left,int right) 
{    
   char temp[61]; 
   strcpy(temp,array[left]); 
   strcpy(array[left],array[right]); 
   strcpy(array[right],temp); 
} 
void Qsort(int left,int right) 
{ 
   int pos; 
   int last; 
   int loop; 
      if(left>=right) 
      return ; 
   pos=(left+right)/2; 
   swap(left,pos); 
   last=left; 
   for(loop=left+1;loop<=right;loop++) 
      if(strcmp(array[loop],array[left])<0) 
         swap(loop,++last); 
   swap(left,last); 
   Qsort(left,last-1); 
   Qsort(last+1,right); 
} 


int calcom() 
{    
   int loop; 
   for(loop=31;loop*(longest+2)+longest > 60;loop--) 
      ; 
   return loop+1; 
            
} 

void change(int index) 
{    
   int loop; 
   for(loop=0;array[index][loop]!='\0';loop++) 
      ; 
   for(;loop<longest+2;loop++) 
      array[index][loop]=' '; 
   array[index][loop]='\0'; 
} 

void PR() 
{ 
  int com=calcom(); 
  int row; 
  int loop,lp; 
  if(Size%com==0) 
   row=Size/com; 
  else 
   row=Size/com+1; 
   printf("------------------------------------------------------------\n"); 

  for(loop=0;loop<row;loop++){ 
     for( lp=loop;lp<Size-row;lp+=row){ 
        change(lp); 
        printf("%s",array[lp]); 
     } 
     printf("%s",array[lp]); 
     printf("\n"); 
  } 

} 
int main() 
{ 
    
   int temp; 
   while(scanf("%d",&Size)!=EOF) 
   {    
      getchar(); 
      longest=0; 
      for(int loop=0;loop<Size;loop++){ 
         scanf("%s",array[loop]); 
         temp=strlen(array[loop]); 
         longest= temp > longest ? temp:longest; 
      } 
      Qsort(0,Size-1); 
       
      PR(); 
   } 
   return 0; 
}
