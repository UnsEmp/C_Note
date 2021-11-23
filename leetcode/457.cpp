#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int> & nums) {
        int k = 1;
        int n = nums.size();
        for(int i = 0;i < n - 1;i++) {
            int ans = i;
            int count = 1;
            int front = ans, temp;
            bool flag = false;
            if(nums[ans] > 0) {
                while(nums[ans] > 0 && count <= n) {
                    temp = nums[ans];
                    ans = (ans + temp) % n;
                    if(ans == front) {
                        if(count > 1) {
                            return true;
                        }
                        break;
                    }
                    count++;
                }
            }
            else {
                while(nums[ans] < 0 && count <= n) {
                    temp = nums[ans];
                    ans = (ans + temp + n) % n;
                    if(ans < 0) {
                        ans %= n;
                        ans += n;
                    }
                    if(ans == front) {
                        if(count > 1) {
                            return true;
                        }
                        break;
                    }
                    count++;
                }
            }

        }
        return false;
    }
};