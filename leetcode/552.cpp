#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        char arr[] = {'L', 'P'};
        // string s = "";
        long long sum = 1;
        // for(int i = 0;i < n;i++) {
        //     s += 'P';
        // }
        for(int i = 0;i < n;i++) {
            int count = 1;
            sum = (sum + 1) % 1000000007;
            for(int j = i + 1;j < n;j++) {
                
                if(count > 0 && count < 2) {
                    sum = (sum + 1) % 1000000007;
                    if(count == 2) {
                        count = 0;
                        j++;
                    }
                }
            }
        }
        sum = (sum * n) % 1000000007;
        // int temp = 1;
        // for(int i = n;i > 0;i--) {
        //     temp *= i;
        //     sum = (sum + temp) % 1000000007;
        // }
        return sum;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().checkRecord(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}