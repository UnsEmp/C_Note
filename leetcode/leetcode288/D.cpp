#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    vector<ll> prefix;
    ll mif, maf;
    ll check(vector<int> & fl, ll nf, int ta, int fu, int pa, int be) {
        int n = fl.size();
        int nbe = n - be;
        ll sum = be * fu;
        ll i = lower_bound(fl.begin(), fl.end(), ta) - fl.begin() - 1, j = n - be;
        if(i >= j) nf -= (ta * (i - j + 1)) - (prefix[i + 1] - prefix[j]);
        cout << nf << "\n";
        if(nbe > 0) {
            int l = mif, r = maf;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                j = lower_bound(fl.begin(), fl.begin() + n - be, mid) - fl.begin() - 1;
                if((mid * (j + 1)) - prefix[j + 1] <= nf) l = mid;
                else r = mid - 1;
            }
            sum += l * pa;
        }
        cout << sum << "\n";
        return sum;
    }
    ll maximumBeauty(vector<int>& flowers, ll newFlowers, int target, int full, int partial) {
        int n =flowers.size(), l = 0, r = 0;
        ll nf = newFlowers;
        sort(flowers.begin(), flowers.end());
        mif = flowers[0], maf = target - 1;
        prefix.push_back(0);
        for(int i = 0;i < n;++i) {
            if(flowers[n - i - 1] >= target) l++;
            else if(nf >= (target - flowers[n - i - 1])) {
                nf -= (target - flowers[n - i - 1]);
                r++;
            }
            prefix.push_back(prefix[i] + flowers[i]);
        }
        r += l;
        ll ans = 0;
        // cout << l << " " << r << "\n";
        for(int i = l;i <= r;++i) {
            if(i == 3) {
                cout << "ok";
            }
            ans = max(ans, check(flowers, newFlowers, target, full, partial, i));
        }
        return ans;
    }
};

signed main() {
    Solution so;
    vector<int> flowers = {2,4,5,3};
    ll newFlowers = 10;
    int target = 5, full = 2, partial = 6;
    cout << so.maximumBeauty(flowers, newFlowers, target, full, partial) << "\n";
    return 0;
}