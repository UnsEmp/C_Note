#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 31;i >= 0;i--) {
            if(((start >> i) & 0) != ((goal >> i) & 0)) ans++; 
        }
        return ans;
    }
};