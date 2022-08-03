#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum = 0;
    int len = 0;
};

class Solution {
public:
    int maximumGroups(vector<int>& gra) {
        int ans = 0, cnt = 0;
        int n = gra.size();
        sort(gra.begin(), gra.end());
        vector<Node> arr;
        // Node no;
        // no.len = 1, no.sum = gra[0];
        arr.push_back({gra[0], 1});
        int i, j = 0, sum, len;
        for(i = 0;i < n;++i) {
            j = i, sum = gra[i], len = 1;
            while(j + 1 < n) {
                if(arr[cnt].sum >= sum || arr[cnt].len >= len) sum += gra[++j], ++ len;
                else break;
            }
            // cout << sum << " " << len << "\n";
            cnt++;
            arr.push_back({sum, len});
            ans ++;
            i = j;
        }
        return arr.size() - 1;
    }
};