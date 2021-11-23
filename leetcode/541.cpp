#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i;
        for(i = 0;i < n && (n - i) >= 2 * k;i += 2 * k) {
            rever(s, i, i + k - 1);
        }
        int temp = (n - i);
        if(temp < k) {
            rever(s, i, n - 1);
        }
        else {
            rever(s, i, i + k - 1);
        }
        return s;
    }
    void rever(string & s, int left, int right) {
        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().reverseStr(s, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}