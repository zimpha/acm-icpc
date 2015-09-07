#include <iostream>

using namespace std;

bool flag;

bool build(int cur, int sum)
{
    int value;
    char c;
    cin >> c;
    if (!((cin >> value)==0))
    {
	cur+=value;
	bool tmp=build(cur,sum)|build(cur,sum);
	if (!tmp && !flag) flag=(cur==sum);
	cin >> c;
	return true;
    }
    else
    {
	cin.clear();
	cin >> c;
	return false;
    }
}

int main()
{
    int sum;
    while (cin >> sum)
    {
	flag=false;
	build(0,sum);
	if (flag) cout << "yes\n";
	else cout << "no\n";
    }
    return 0;
}
