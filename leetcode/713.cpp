#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        int i = 0, j = 0;
        int sum = 1, tmp = 0, count = 0;
        while(i < len && j < len) {
            sum *= nums[j];
            if(sum < k) {
                count += j - i + 1;
                // j++;
            }
            else {
                sum /= nums[i];
                sum /= nums[j];
                i++;
                j--;
                if(sum == 0) {
                    sum = 1;
                    j = i - 1;
                }
            }
            j++;
        }
        return count;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().numSubarrayProductLessThanK(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}