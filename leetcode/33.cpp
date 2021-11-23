#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0;i < nums.size();i++) {
            mp[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        int tmp = fun(nums, 0, nums.size() - 1, target);
        cout << tmp << endl;
        if(tmp == -1) return -1;
        else return mp[tmp];
    }
    int fun(vector<int> nums, int left, int right, int target) {
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] > target) right = mid - 1;
            else if(nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return -1;
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
        int target = stringToInteger(line);
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
