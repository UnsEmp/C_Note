#include <bits/stdc++.h>
using namespace std;
typedef long long int;

class Solution {
public:
    int convertTime(string current, string correct) {
        int cushi = (current[0] - '0') * 10 + (current[1] - '0'), cufen = (current[3] - '0') * 10 + (current[4] - '0');
        int coshi = (correct[0] - '0') * 10 + (correct[1] - '0'), cofen = (correct[3] - '0') * 10 + (correct[4] - '0');
        cufen += cushi * 60;
        cofen += coshi * 60;
        int ans = 0;
        while(cufen < cofen) {
            if(cufen + 60 <= cofen)
            {
                cufen += 60;
                ans ++;
            }
            else if(cufen + 15 <= cofen) {
                cufen += 15;
                ans ++;
            }
            else if(cufen + 5 <= cofen) {
                cufen += 15;
                ans ++;
            }
            else {
                cufen += 1;
                ans ++;
            }
            cufen %= (24 * 60);
        }
        return ans;
    }
};