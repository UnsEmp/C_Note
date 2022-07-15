#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(string s1, string s2) {
        map<char, int> mp1, mp2;
        for(int i = 0;i < s1.size();++i) mp1[s1[i]] ++;
        for(int i = 0;i < s2.size();++i) {
            mp2[s2[i]] ++;
        }
        for(char ch = 'a';ch <= 'z';++ch) {
            if(mp1[ch] != mp2[ch]) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> arr;
        while(1) {
            int cnt = 0;
            arr.push_back(words[0]);
            // int i;
            // for(i = 1;i < words.size();++i) {
            //     if(judge(words[i], words[i - 1])) {
            //         cnt ++;
            //         break;
            //     }
            //     else arr.push_back(words[i]);
            // } 
            // for(;i < words.size();++i) arr.push_back(words[i]);
            // // for(int )
            // if(cnt == 0) break;
            // while(words.size()) words.pop_back();
            // for(int i = 0;i < arr.size();++i) words.push_back(arr[i]);
            // while(arr.size()) arr.pop_back();
            int i;
            for(i = 1;i < words.size();++i) {
                if(judge(words[i], words[i - 1])) {
                    cnt ++;
                    i ++;
                    break;
                }
                else arr.push_back(words[i]);
            }
            for(;i < words.size();++i) {
                arr.push_back(words[i]);
            }
            for(i = 0;i < arr.size();++i) cout << arr[i] << " ";
            cout << "\n";
            if(cnt == 0) break;
            while(words.size()) words.pop_back();
            for(int i = 0;i < arr.size();++i) words.push_back(arr[i]); 
            while(arr.size()) arr.pop_back();
        }
        return arr;
    }
};