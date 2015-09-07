#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=2000;

string a[MAXN];
int n;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
	string buff;
	cin >> a[i];
	getline(cin,buff);
    }
    sort(a,a+n);
    for (int i=0; i<n; i++)
    {
	int sum,j;
	for (j=i,sum=0; j<n&&a[i]==a[j]; j++,sum++);
	cout << a[i]+" " << sum <<endl;
	i=j-1;
    }
    return 0;
}
