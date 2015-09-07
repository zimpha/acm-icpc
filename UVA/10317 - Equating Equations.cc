    #include<cstdio>  
    #include<cstring>  
      
    const int maxn = 1000;  
    char str[10000];  
    char sigma[maxn];  
    bool vis[maxn];  
    int  num[maxn], ans[maxn], n, idx;  
    int  plus[maxn], leftNum, plusNum, sum;  
      
      
    inline void read(){  
        idx = 1;  
        sscanf(str, "%d", &num[0]);  
        sum = num[0];  
        int len = strlen(str);  
        for(int i=1; i<len; ++i){  
            if(str[i]=='+' || str[i]=='-' || str[i]=='=') {  
                if(str[i] == '=')   
                    leftNum = idx;  
                sigma[idx] = str[i];  
                sscanf(str+i+1, "%d", &num[idx]);  
                sum += num[idx++];  
            }  
      
        }  
        // 把等式全部移到左边后，计算有多少个加号  
        plusNum = 1;  
        for(int i=1; i<idx; ++i){  
            if(i<leftNum && sigma[i] == '+'){   
                ++plusNum;  
            } else if(i>leftNum && sigma[i] == '-')   
                ++plusNum;  
          
        }  
    }  
      
    bool dfs(int cur, int pos, int tot){  
        if(plusNum-cur > idx-pos)  
            return false;  
        if(cur == plusNum){  
            if(tot*2 == sum) return true;  
            return false;  
      
        }  
        if(pos<idx && (tot+num[pos])*2 <= sum){  
            vis[pos] = true;  
            plus[cur] = num[pos];  
            if(dfs(cur+1, pos+1, tot+num[pos]))   
                return true;  
      
        }  
        vis[pos] = false;  
        if(pos<idx && dfs(cur, pos+1, tot))  
            return true;  
        return false;  
      
    }  
      
    inline void solve(){  
        //注意减枝！如果sum为奇数那么直接输出no solution  
        memset(vis, 0, sizeof(vis));  
        if((sum&1)==0 && dfs(0, 0, 0)){   
            int id=1;  
            ans[0] = plus[0];  
            for(int i=1; i<idx; ++i){  
                if(i<leftNum && sigma[i]=='+') {  
                    ans[i] = plus[id++];  
                } else if(i>leftNum && sigma[i]=='-'){  
                    ans[i] = plus[id++];  
                }  
      
            }  
            int k=1;  
            for(int i=0; i<idx; ++i)if(!vis[i]){  
                while(k<leftNum && sigma[k]=='+' && k<idx) ++k;  
                while(k>leftNum && sigma[k]=='-' && k<idx) ++k;  
                ans[k++] = num[i];  
      
            }  
            printf("%d", ans[0]);  
            for(int i=1; i<idx; ++i)  
                 if(i==leftNum) printf(" = %d",ans[i]);  
                 else printf(" %c %d", sigma[i], ans[i]);  
            puts("");  
      
        }else{  
            puts("no solution");  
          
        }  
      
    }  
      
    int main(){  
      
        while(gets(str)){  
            read();  
            solve();  
        }  
      
        return 0;  
    }  
