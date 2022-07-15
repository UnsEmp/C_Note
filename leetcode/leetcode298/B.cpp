#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        map<int, int> mp;
        for(int i = 10;i >= 1;--i) mp[(i * k) % 10] = i;
        if(!mp[(num % 10)]) return -1;
        int t = mp[num % 10];
        if(t * k <= num) return t;
        else return -1;
    }
};