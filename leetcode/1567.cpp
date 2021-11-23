#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int position = 0, negitive = 0, left = 0;
        int Max = 0;
        int n = nums.size();
        for(int i = 0;i <= n;i++) {
            if(i == n || nums[i] == 0) {
                if(negitive % 2 == 1) {
                    negitive = 0;
                    int temp = max(position - left, (i - left - 1) - (position - left));
                    Max = max(temp, Max);
                }
                else {
                    Max = max(Max, (i - left));
                }
                left = i + 1;
                // count = 0;
            }
            else {
                if(nums[i] < 0) {
                    negitive++;
                    if(negitive % 2 == 1) position = i;
                }
            }
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
        
        int ret = Solution().getMaxLen(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}