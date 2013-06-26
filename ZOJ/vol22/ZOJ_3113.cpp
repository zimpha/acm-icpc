#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int sg,n,tmp;
    int test;
    bool flag;
    cin>>test;
    while (test--)
    {
        cin>>n;
        flag=false;
        sg=0;
        while (n--)
        {
            cin>>tmp;
            sg^=tmp;
            if (tmp>1) flag=true;
        }
        if ((sg!=0&&flag)||(sg==0&&!flag)) cout<<"John\n";
        else cout<<"Brother\n";
    }
    return 0;
}
