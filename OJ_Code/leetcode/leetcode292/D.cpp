#include <bits/stdc++.h>
#include <fstream>
using namespace std;
using ll = long long;
using pii = pair<int,int>;


// class Solution {
// public:
    
//     bool isValid(string s) {
//         unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},
//                                 {')',4},{']',5},{'}',6}};
//         stack<char> st;
//         bool istrue=true;
//         for(char c:s){
//             int flag=m[c];
//             if(flag>=1&&flag<=3) st.push(c);
//             else if(!st.empty()&&m[st.top()]==flag-3) st.pop();
//             else {istrue=false;break;}
//         }
//         if(!st.empty()) istrue=false;
//         return istrue;
//     }
//     int dir[2][2] = {{1, 0}, {0, 1}};
//     int n, m;
//     map<pair<int,int>, int> mp;
//     bool flag = false;
//     void dfs(vector<vector<char>>& grid ,int x, int y, string s) {
//         if(x == n - 1 && y == m - 1) {
//             // cout << s << "\n";
//             flag = isValid(s);
//             if(isValid(s)) {
//                 flag = true;
//             }
//             return ;
//         }
//         for(int i = 0;i < 2;++i) {
//             if(flag) return ;
//             int nx = x + dir[i][0], ny = y + dir[i][1];
//             if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
//                 if(grid[nx][ny] == '(') dfs(grid, nx, ny,  s + "(");
//                 else dfs(grid, nx, ny, s + ")"); 
//             }
//         }
//     }
//     bool hasValidPath(vector<vector<char>>& grid) {
//         n = grid.size(), m = grid[0].size();
//         string res;
//         int l = 0, r = 0;
//         if(grid[0][0] == '(') {
//             res += "(";
//             l++;
//         }
//         else {
//             res += ")";
//             r++;
//         }
//         dfs(grid ,0, 0, res);
//         // return isValid(")((");
//         return flag;
//     }
// };


class Solution {
public:
    int len;
    set<string> ans;
    void dfs(int l, int r, string s) {
        if(r > l) return ;
        if(l == r && l == len) {
            if(s.size() != 0)
            ans.insert(s);
        }
        if(l > len) return ;
        dfs(l + 1, r, s + "(");
        dfs(l, r + 1, s + ")");
    }
    vector<string> generateParenthesis(int n) {
        string s;
        len = n;
        dfs(0, 0, "");
        vector<string> arr(ans.begin(), ans.end());
        return arr;
    }
};


int main() {
    Solution so;
    ofstream wi("text.txt");
    int n;
    cin >> n;
    auto arr = so.generateParenthesis(n);
    // for(int i = 0;i < arr.size();++i) wi << arr[i] << "\n";
    for(int i = 0;i < arr.size();++i) cout << arr[i] << "\n";
    // cout << "\n";
}