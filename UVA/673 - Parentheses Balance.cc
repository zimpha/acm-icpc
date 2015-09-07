#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test; cin.get();
    while (test--)
    {
	string exp;
	getline(cin,exp);
	stack<int>s;
	bool flag=true;
	while (!s.empty()) s.pop();
	for (int i=0; i<exp.size(); i++)
	{
	    if (exp[i]=='(') s.push(1);
	    else 
		if (exp[i]=='[') s.push(2);
		else 
		    if (exp[i]==')')
			if (!s.empty()&&s.top()==1) s.pop();
			else {flag=false; break;}
		    else
			if (exp[i]==']')
			    if (!s.empty()&&s.top()==2) s.pop();
			    else {flag=false; break;}
	}
	if (flag&&s.empty()) cout << "Yes" << endl;
	else cout << "No" << endl;
    }
    return 0;
}
