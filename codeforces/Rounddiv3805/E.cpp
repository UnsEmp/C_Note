#include <bits/stdc++.h>
using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};


void solve() {
    int n;
    cin >> n;
    dsu d(n * 2);
    vector<int> nums(n);
    for(int i = 0;i < n;++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        nums[a] ++;
        nums[b] ++;
        d.unite(a, b + n);
        d.unite(a + n, b);
    }
    bool flag = true;
    for(int i = 0;i < n;++i) {
        if(nums[i] > 2) flag = false;
        if(d.get(i) == d.get(i + n)) flag = false;
    }
    if(flag) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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