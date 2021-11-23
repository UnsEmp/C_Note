#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        vector<int> Hash;
        Hash.resize(256, -1);
        // return Hash[0];
        int i = 0, j = 0;
        int Max = 0;
        int count = 0;
        while(i < s.size() && j < s.size()) {
            for(;j < s.size() && (Hash[s[j]] == -1 || (Hash[s[j]] < i && Hash[s[j]] >= 0));j++) {
                Hash[s[j]] = j;
                count++;
            }
            Max = max(Max, count);
            count = j - Hash[s[j]] - 1;
            i = Hash[s[j]] + 1;
            // j++;
            // cout << i << endl;
        }
        return Max;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}