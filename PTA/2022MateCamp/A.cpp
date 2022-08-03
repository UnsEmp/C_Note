#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int n, m;
    cin >> n;
    vector<string> nums1(n);
    vector<string> arr;
    unordered_map<string, int> mp, sign;
    // int cnt = 0;
    for(int i = 0;i < n;++i) {
        cin >> nums1[i];
    }
    cin >> m;
    vector<string> nums2(m);
    for(int i = 0;i < m;++i) {
        cin >> nums2[i];
    }
    int q;
    cin >> q;
    string s;
    for(int i = 0;i < q;++i) {
        cin >> s;
        mp[s] ++;
    }


    int cnt = 0;
    for(int i = 0;i < n;++i) {
        if(cnt < k && mp[nums1[i]]) {
            // cout << nums1[i] << "\n";
            arr.push_back(nums1[i]);
            // mp[nums1[i]] ++;
            sign[nums1[i]] ++;
            cnt ++;
        }
    }
    cnt = 0;
    for(int i = 0;i < m;++i) {
        if(cnt < k && !sign[nums2[i]] && mp[nums2[i]]) {
            cnt ++;
            // cout << nums1[i] << "\n";
            arr.push_back(nums2[i]);
        }
    }
    sort(arr.begin(), arr.end());

    cout << arr.size() << "\n";
    for(int i = 0;i < arr.size();++i) cout << arr[i] << "\n";
    return 0;
}