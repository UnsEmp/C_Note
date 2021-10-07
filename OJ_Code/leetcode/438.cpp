#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // int i = 0, j = 0;
        int n = s.size();
        int m = p.size();
        map<char, int> mp;
        for(int k = 0;k < m;k++) mp[p[k]]++; 
        vector<int> ans;
        // while(i < n) {
        //     if(mp[s[i]]) {

        //     }
        // }
        for(int i = 0;i <= n - m;) {
            bool flag = true;
            int j = i;
            map<char, int> sign;
            for(;j < i + m;j++) {
                // cout << i << endl;
                if(mp[s[j]] && (sign[s[j]] < mp[s[j]])) {
                    sign[s[j]]++;
                    continue;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(i);
            }
            i++;
        }
        return ans;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        vector<int> ret = Solution().findAnagrams(s, p);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}