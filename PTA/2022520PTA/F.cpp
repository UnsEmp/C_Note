#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1;i <= n; ++i) {
        cin >> nums[i];
    }
    int r = (double)n / 2.718;
    // cout << r << "\n";
    int score = 0, l = 0;
    for(int i = 1;i <= r;++i) {
        if(nums[i] > score) {
            score = nums[i];
        }
    }
    int ri = 0;
    for(int i = r + 1;i <= n;++i) {
        if(nums[i] > score) {
            l = i;
            break;
        }
    }
    score = 0;
    for(int i = 1;i <= n;++i) {
        if(nums[i] > score) {
            score = nums[i];
            ri = i;
        }
    }
    if(ri) {
        cout << l << " " << ri << "\n";
    }
    else cout << ri << "\n";
    return 0;
}