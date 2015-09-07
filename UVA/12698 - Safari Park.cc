#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define SZ(x) x.size()
const int SIZE = 300010;
int tn, N;

struct Point{
    int x,y;
    Point(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator==(const Point& b){return x==b.x&&y==b.y;}
    bool operator!=(const Point& b)const{return x!=b.x||y!=b.y;}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    long long operator*(const Point& b){return (long long)x*b.y-(long long)y*b.x;}
}tri[50002][4];

int ccheck(const Point& X,int id){
    bool on_edge=false;
    REP(i,3){
        long long tmp=(tri[id][i+1]-tri[id][i])*(X-tri[id][i]);
        if(tmp>0)return 0;
        if(!tmp)on_edge=true;
    }
    if(on_edge)return -1;
    return id;
}

bool point_to_edge(const Point& X,const Point& L,const Point& R){
    return (R-L)*(X-L)<0;
}

bool edge_to_edge(const Point& L,const Point& R,const Point& L2,const Point& R2){
    if(L.x>=L2.x&&L.x<=R2.x){
        if(L!=L2)return point_to_edge(L,L2,R2);
    }
    if(L2.x>=L.x&&L2.x<=R.x){
        if(L2!=L)return !point_to_edge(L2,L,R);
    }
    if(R.x>=L2.x&&R.x<=R2.x){
        if(R!=R2)return point_to_edge(R,L2,R2);
    }
    if(R2.x>=L.x&&R2.x<=R.x){
        if(R!=R2)return !point_to_edge(R2,L,R);
    }
    return 0;
}

struct Compare{
    bool operator()(int x,int y){
        int x_id=x>>2;
        int x_pid=x&3;
        int x_pid2=x_pid+1;
        if(tri[x_id][x_pid].x>tri[x_id][x_pid2].x)swap(x_pid,x_pid2);
        int y_id=y>>2;
        int y_pid=y&3;
        int y_pid2=y_pid+1;
        if(tri[y_id][y_pid].x>tri[y_id][y_pid2].x)swap(y_pid,y_pid2);

        if(tri[x_id][x_pid]==tri[x_id][x_pid2])return point_to_edge(tri[x_id][x_pid],tri[y_id][y_pid],tri[y_id][y_pid2]);
        if(tri[y_id][y_pid]==tri[y_id][y_pid2])return !point_to_edge(tri[y_id][y_pid],tri[x_id][x_pid],tri[x_id][x_pid2]);
        return edge_to_edge(tri[x_id][x_pid],tri[x_id][x_pid2],tri[y_id][y_pid],tri[y_id][y_pid2]);
    }
};


multiset<int,Compare>H[400000];
int now_l,now_r,now_id,now_pid;

int query(int L,int R,int id){
    int res=0;
    if(SZ(H[id])){
        multiset<int,Compare>::iterator it=H[id].lower_bound(tn<<2);
        if(it!=H[id].end()){
            res=ccheck(tri[tn][0],(*it)>>2);
            if(res)return res;
            multiset<int,Compare>::iterator it2=it;
            it2++;
            if(it2!=H[id].end()){
                res=ccheck(tri[tn][0],(*it2)>>2);
                if(res)return res;
            }
        }
        if(it!=H[id].begin()){
            it--;
            res=ccheck(tri[tn][0],(*it)>>2);
            if(res)return res;
            if(it!=H[id].begin()){
                it--;
                res=ccheck(tri[tn][0],(*it)>>2);
                if(res)return res;
            }
        }
    }
    if(L+1>=R)return res;
    int mm=(L+R)>>1;
    if(tri[tn][0].x<=mm){
        res=query(L,mm,id<<1);
        if(res)return res;
    }
    if(tri[tn][0].x>=mm){
        res=query(mm,R,(id<<1)|1);
        if(res)return res;
    }
    return res;
}

void add(int L,int R,int id){
    if(now_l<=L&&now_r>=R){
        //fprintf(stderr,"[%d,%d]\n",L,R);
        H[id].insert((now_id<<2)|now_pid);
        return;
    }
    int mm=(L+R)>>1;
    if(now_l<mm)add(L,mm,id<<1);
    if(now_r>mm)add(mm,R,(id<<1)|1);
}

int main(){
    int case_n = 1, T; scanf("%d", &T);
    while (T--) {
        int d=0;
        REP(i,400000)H[i].clear();
        scanf("%d", &N);
        //DRI(N);
        printf("Case %d:\n",case_n++);
        tn=1;
        while(N--){
            char s[4];
            scanf("%s", s);
            //RS(s);
            if(s[0]=='Q'){
                int x, y; scanf("%d%d", &x, &y);
                //DRII(x,y);
                if(d>0){x+=tri[d][0].x;y+=tri[d][0].y;}
                tri[tn][0]=tri[tn][1]=Point(x,y);
                now_l=now_r=x;
                //if(now_l<0||now_r>100000)while(1);
                now_id=tn;
                d=query(0,100000,1);
                printf("%d\n",d);
            }
            else if(s[0]=='R'){
                //REP(i,3)RII(tri[tn][i].x,tri[tn][i].y);
                REP(i,3) scanf("%d%d", &tri[tn][i].x,&tri[tn][i].y);
                if(d>0)REP(i,3){tri[tn][i].x+=tri[d][0].x;tri[tn][i].y+=tri[d][0].y;}
                tri[tn][3]=tri[tn][0];
                now_id=tn;
                REP(i,3){
                    now_pid=i;
                    now_l=tri[tn][i].x;
                    now_r=tri[tn][i+1].x;
                    if(now_l!=now_r){
                        //if(now_l<0||now_r>100000)while(1);
                        if(now_l>now_r)swap(now_l,now_r);
                        add(0,100000,1);
                    }
                }
                tn++;
            }
        }
    }
    return 0;
}
