#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,year,month,day;
    scanf( "%d",&n );
    while( n-- )
    {
        scanf( "%d%d%d",&year,&month,&day );
        if( month==9 && day==30 ) printf( "YES\n" );
        else if( month==11 && day==30 ) printf( "YES\n" );
        else if( (month+day)%2==0 ) printf( "YES\n" );
        else printf( "NO\n" );
    }
    return 0;
}

