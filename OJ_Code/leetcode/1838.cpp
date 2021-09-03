#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        vector<int> ans;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();i++) {
            sum += nums[i];
            ans.emplace_back(sum);
        }
        int l = 1, r = nums.size(), mid;
        while(l < r) {
            mid = (l + r >> 1);
            if(judge(ans, mid, k)) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
    }
    bool judge(vector<int> & ans,int len, int k) {
        for(int i = 0;i + len - 1 < ans.size();i++) {
            if(ans[i + len] - ans[i] + k >= ans[i + len - 1] * len)
                return true;
        }
        return false;
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
        
        int ret = Solution().maxFrequency(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}