    #include <iostream>  
    #include <fstream>  
    #include <map>  
    #include <algorithm>  
      
    using namespace std;  
      
    map<char, char> charMap;  
    map<char, char> intMap;  
      
    string add(string a, string b);  
    void Right(string &s);  
    void Left(string &s);  
      
      
    int main()  
    {  
        int n;  
        string num1, num2;  
        string op;  
        string res;  
      
    #ifndef ONLINE_JUDGE  
        ifstream cin("d:\\OJ\\uva_in.txt");  
    #endif  
      
        charMap['V'] = '0';  
        charMap['U'] = '1';  
        charMap['C'] = '2';  
        charMap['D'] = '3';  
      
        intMap['0'] = 'V';  
        intMap['1'] = 'U';  
        intMap['2'] = 'C';  
        intMap['3'] = 'D';  
      
        cout << "COWCULATIONS OUTPUT" << endl;  
        cin >> n;  
        while (n--) {  
            cin >> num1 >> num2;  
            //cout << "num1:" << num1 << " num2:" << num2 << endl;  
            for (int i = 0; i < 3; i++) {  
                cin >> op;  
                if (op == "A") {  
                    num2 = add(num1, num2);  
                } else if (op == "L") {  
                    Left(num2);  
                } else if (op == "R") {  
                    Right(num2);  
                }  
            }  
      
            if (num2.size() < 8) {  
                num2.insert(0, 8 - num2.size(), 'V');  
            }  
      
            //cout << "num2:" << num2 << endl;  
            cin >> res;  
      
            if (num2 == res) {  
                cout << "YES" << endl;  
            } else {  
                cout << "NO" << endl;  
            }  
        }  
        cout << "END OF OUTPUT" << endl;  
        return 0;  
    }  
      
    string add(string a, string b)  
    {  
        //cout << "a:" << a << " b:" << b << " ";  
        for (size_t i = 0; i < a.size(); i++) {  
            a[i] = charMap[a[i]];  
        }  
      
        for (size_t i = 0; i < b.size(); i++) {  
            b[i] = charMap[b[i]];  
        }  
      
        //cout << "a:" << a << " b:" << b ;  
        reverse(a.begin(), a.end());  
        reverse(b.begin(), b.end());  
      
        int carry = 0;  
        int i;  
        string res = "";  
      
        for (i = 0; i < a.size() && i < b.size(); i++) {  
            int sum = (a[i] - '0') + (b[i] - '0') + carry;  
            res += ('0' + sum % 4);  
            carry = sum / 4;  
        }  
      
        for (; i < a.size(); i++) {  
            int sum = (a[i] - '0') + carry;  
            res += ('0' + sum % 4);  
            carry = sum / 4;  
        }  
      
        for (; i < b.size(); i++) {  
            int sum = (b[i] - '0') + carry;  
            res += ('0' + sum % 4);  
            carry = sum / 4;  
        }  
      
        if (carry) res += '1';  
      
        reverse(res.begin(), res.end());  
      
        //cout << " res:" << res << endl;  
        for (size_t i = 0; i < res.size(); i++) {  
            res[i] = intMap[res[i]];  
        }  
      
      
        return res;  
    }  
      
      
    void Right(string &s)  
    {  
        s.erase(s.size() - 1, 1);  
        s = 'V' + s;  
      
    }  
      
    void Left(string &s)  
    {  
        s += 'V';  
    }  
