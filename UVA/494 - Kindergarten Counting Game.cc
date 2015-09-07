#include <string>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str;
	while (getline(cin,str))
	{
		int i,n=str.size(),count=0;
		bool flag=0;
		for (i=0;i<n;i++)
		{
			if ((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
			{
				if (!flag) flag=1,count++;
			}
			else flag=0;
		}
		cout<<count<<endl;
	}
	return 0;
}
