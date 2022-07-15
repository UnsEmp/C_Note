#include <bits/stdc++.h>
using namespace std;

vector<int> arr(7);
bool check(int x) {
    for(int i = 0;i < 7;++i) {
        int t = arr[i];
        if((x >> i) & 1) t --;
        if((x >> i) & 1) {
            if(t & 1) continue;
            else return false;
        }
        else {
            if(!(t & 1)) continue;
            else return false;
        }
    }
    return true;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;++i) {
        cin >> nums[i];
        int t = nums[i];
        for(int j = 0;j < 7;++j) {
            if((t >> j) & 1) arr[j] ++;
        }
    }
    cout << nums[0] << "\n";
    // for(int i = 0;i < n;++i) {
    //     if(check(nums[i])) {
    //         cout << nums[i] << "\n";
    //         return ;
    //     }
    // }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}