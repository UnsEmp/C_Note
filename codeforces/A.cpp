#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long ans = 0;
    int check(vector<int> & fl, long long nf, int ta, int fu, int pa, int mid) {
        priority_queue<int> q;
        for(auto f : fl) q.push(f);
        for(int i = 0;i < mid;++i) {
            if(q.top() < ta) {
                nf -= ta - q.top();
            }
            q.pop();
        }
        cout << nf << "\n";
        while(nf > 0) {
            auto t = q.top();
            q.pop();
            q.push(t + 1);
            nf--;
        }
        return q.top();
    }
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        
        long long ans = 0;
        priority_queue<int> q;
        int l = 0, r = 0;
        for(auto f : flowers) {
            if(f >= target) l++;
            q.push(f);
        }
        int ta = target;
        while(q.size() && ta >= (target - q.top())) {
            if(q.top() <= target) {
                ta -= (target - q.top());
                // q.pop()
            } 
            q.pop();
        }
        r = n - q.size();
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            cout << l << " " << mid << " " << r << "\n";
            int t = check(flowers, newFlowers, target, full, partial, mid);
            if(t > ans) {
                l = mid;
                ans = t;
            }
            else r = mid - 1;
        }
        return ans;
    }
};