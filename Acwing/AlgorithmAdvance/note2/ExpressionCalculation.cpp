#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> g;
    g['+'] = g['-'] = 1;
    g['*'] = g['/'] = 2;
    g['^'] = 3;
    stack<char> st;
    string res;
    for(int i = 0;i < s.size();++i) {
        if(isdigit(s[i])) res += s[i];
        else {
            if(st.empty()) {
                st.push(s[i]);
            }
            else {
                if(s[i] == '(') {
                    st.push(s[i]);
                }
                else if(s[i] == ')') {
                    while(st.size() && st.top() != '(') {
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else {
                    while(st.size() && g[st.top()] >= g[s[i]]) {
                        res += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                
            }
        }
    } 
    while(st.size()) {
        if(st.top() == '(') {
            st.pop();
            continue;
        }
        res += st.top();
        st.pop();
    }
    stack<int> ss;
    for(int i = 0;i < res.size();++i) {
        if(isdigit(res[i])) ss.push(res[i] - '0');
        else {
            int b, a, c;
            b = ss.top(), ss.pop();
            a = ss.top(), ss.pop();
            // cout << a << " " << b << "\n";
            switch(res[i]) {
                case '+':c = a + b;break;
                case '-':c = a - b;break;
                case '*':c = a * b;break;
                case '/':c = a / b;break;
                case '^':c = (int)pow(a, b);break;
            }
            ss.push(c);
        }
        // cout << ss.size() << "\n";
    }

    cout << ss.top() << "\n";
    // cout << res << "\n";
    return 0;
}