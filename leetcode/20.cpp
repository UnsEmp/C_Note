#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        // mystack.push(s[0]);
        for(int i = 0;i < s.size();i++) {
            if(mystack.empty()) {
                mystack.push(s[i]);
                continue;
            }
            char ch = mystack.top();
            if((ch == '(' && s[i] == ')') || (ch == '{' && s[i] == '}') || (ch == '[' && s[i] == ']'))
                mystack.pop();
            else
                mystack.push(s[i]);
        }
        // cout << mystack.size() << endl;
        return mystack.empty();
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    // int a = 10, b = 12;
    // a = a^b;
    // b = a^b;
    // a = a^b;
    // cout << a << " " <<  b << endl;
    return 0;
}