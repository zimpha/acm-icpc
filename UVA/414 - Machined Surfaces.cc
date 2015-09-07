#include <algorithm>
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,a[15];
	string str;
	while (cin>>n)
	{
		if (!n) break;
		int max=0,sum=0;
		getline(cin,str);
		for (int i=0;i<n;i++)
		{
			getline(cin,str);
			a[i]=0;
			for (int j=0;j<str.size();j++)
			{
				if (str[j]=='X') a[i]++;
			}
			sum+=a[i];
			if (a[i]>max) max=a[i];
		}
		cout<<max*n-sum<<endl;
	}
	return 0;
}
