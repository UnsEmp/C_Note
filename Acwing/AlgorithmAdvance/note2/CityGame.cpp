#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int w;
    int h;
    Node() {
        w = 1, h = 1;
    }
    Node(int a, int b) {
        w = a, h = b;
    } 
};

int getm(vector<int> & nums) {
    Node nd;
    stack<Node> st;
    int ans = 0;
    for(int i = 0;i < nums.size();++i) {
        nd.w = 1, nd.h = nums[i];
        if(st.empty()) {
            st.push(nd);
        }
        else {
            if(st.top().h <= nums[i]) {
                st.push({1, nums[i]});
            }
            else {
                int w = 0;
                while(st.size() && st.top().h > nums[i]) {
                    w += st.top().w;
                    ans = max(ans, w * st.top().h);
                    st.pop();
                }   
                st.push({w + 1, nums[i]});
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> nums(n, vector<char>(m));
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            cin >> nums[i][j];
        }
    }
    for(int i = 0;i < n;++i) {
        for(int j = 0;j < m;++j) {
            int s = 0, t = i;
            while(t >= 0 && nums[t][j] == 'F') {
                s ++;
                t --;
            }
            arr[i][j] = s;
        }
    }

    int ans = 0;
    for(int i = 0;i < n;++i) {
        ans = max(ans, getm(arr[i]));
    }
    cout << ans * 3 << "\n";
    return 0;
}