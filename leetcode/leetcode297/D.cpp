#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> mp;
        for(auto & i : ideas) {
            mp[i.substr(1)] |= (1 << (i[0] - 'a'));
        }
        
    }
};