#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int top = 0;
        int num = 1, sum = 0;
        while(sum < label) {
            sum += num;
            num *= 2;
            top++;
        }
        vector<int> ans;
        int n;
        num = label;
        if(top % 2 == 0)
            n = g(2, top) - 1 - label;
        else
            n = label - g(2, top - 1);
        while(top) {
            int temp;
            if(top % 2 == 1) {
                temp = g(2, top - 1);
                num = temp + n;
                ans.push_back(num);
                if(num % 2 == 0)
                    num++;
                n = (num - temp + 1) / 2 - 1;
            }
            else {
                temp = g(2, top) - 1;
                num = temp - n;
                ans.push_back(num);
                if(num % 2 == 1)
                    num--;
                n = (temp - num + 1) / 2 - 1;
            }
            top--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int g(int n, int m) {
        if(m == 0)
            return 1;
        if(m % 2 == 1) {
            return n * g(n, m - 1);
        }
        else {
            int num = g(n, m / 2);
            return num * num;
        }
    }
};


int stringToInteger(string input) {
    return stoi(input);
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
        int label = stringToInteger(line);
        
        vector<int> ret = Solution().pathInZigZagTree(label);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}