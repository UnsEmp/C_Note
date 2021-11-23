#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while((n)) {
            if((n & 1)) count++;
            n = n >> 1;
        }
        return count; 
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    // int arr[2][3] = {{1, 2, 3}, { 4, 5, 6}};
    // cout << arr[0][0] << " " << arr[1][0]; 
    // return 0;
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().hammingWeight(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}