#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int Max = INT_MIN;
        while(i / n < 2) {
            if(i - j <= n - 1) {
                sum += nums[i % n];
            }
            else
                sum = nums[i % n];
            Max = max(sum, Max);
            // if(i - j == n - 1)
            //     sum = nums[i];
            if(sum < 0) {
                sum = 0;
                j = i;
            }
            // cout << i << endl;
            i++;
        }
        return Max;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxSubarraySumCircular(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}