#include <cstdio>
#include <string>
#include <iostream>

typedef long long LL;

int main()
{
    std::string s;
    while (std::cin >> s)
    {
	if (s=="0") break;
	LL l=s.size();
	LL n=0;
	for (int i=0; i<s.size(); i++)
	{
	    LL digit=s[i]-'0';
	    n+=digit*(1LL<<l)-digit;
	    l--;
	}
	printf("%lld\n",n);
    }
    return 0;
}
