#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

int main() {
    // map<int, vector<int>> mpx, mpy;
    vector<PII> arr;
    PII p;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> p.first >> p.second;
        arr.push_back(p);
    }
    int count = 0, i, j;
    for(i = 0;i < n;i++) {
        bool l, r, u, d;
        l = r = u = d = false;
        for(j = 0;j < n;j++) {
            if(i == j) continue;
            if(arr[i].first == arr[j].first && arr[j].second > arr[i].second) l = true;
            if(arr[i].first == arr[j].first && arr[j].second < arr[i].second) r = true;
            if(arr[i].second == arr[j].second && arr[j].first > arr[i].first) u = true;
            if(arr[i].second == arr[j].second && arr[j].first < arr[i].first) d = true;
        }
        if(l && r && u && d) count++;
    }
    cout << count << endl;
    
    return 0;
}