#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mp;
        map<char, int> sign;
        // char mp[128];
        int i = 0;
        char ch = 'a';
        while(i < key.size() && ch <= 'z') {
            if(key[i] != ' ') {
                if(!sign[key[i]]) {
                    sign[key[i]] ++;
                    mp[key[i]] = ch++;
                }
            }
            i++;
        }
        for(i = 0;i < message.size();++i) {
            if(message[i] == ' ') continue;
            else message[i] = mp[message[i]];
        }
        return message;
    }
};