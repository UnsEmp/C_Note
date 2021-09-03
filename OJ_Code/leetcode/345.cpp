#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> mp;
        char arr[] = {'a', 'e', 'o', 'u', 'i', 'A', 'E', 'O', 'U', 'I'};
        for(int i = 0;i < 10;i++) {
            mp[arr[i]]++;
        }
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(!mp[s[i]])
                i++;
            if(!mp[s[j]])
                j--;
            if(mp[s[i]] && mp[s[j]]) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};