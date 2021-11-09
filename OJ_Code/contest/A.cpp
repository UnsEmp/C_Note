#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        int count = 1;
        for(int i = 0;i < arr.size();i++) {
            mp[arr[i]]++;
        }
        for(auto it : mp) {
            if(it.second == 1) {
                if(count == k) return it.first;
                else count++;
            }
        }
        for(int i = 0;i < arr.size();i++) {
            if(mp[arr[i]] == 1) {
                if(count == k) return arr[i];
                else count++;
            }
        }
        return ""
        // return "";
        // string s[1001];
        // vector<string> ans[1001];
        // for(int i = 0;i < arr.size();i++) {
        //     ans[arr[i]]++;
        // }
    }
};

int main() {
    return 0;
}