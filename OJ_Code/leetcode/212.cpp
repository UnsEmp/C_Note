#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row, col;
    vector<string> ans;
    map<pair<int, int> ,int> sign;
    map<string, int> mp;
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int Max_len = 0;
        for(int i = 0;i < words.size();i++) {
            mp[words[i]]++;
            int tmp = words[i].size();
            Max_len = max(Max_len, tmp);
        }
        row = board.size();
        col = board[0].size();
        for(int i = 0;i < row;i++) {
            for(int j = 0;j < col;j++) {
                string s = "";
                // s += board[i][j];
                dfs(board, 0, Max_len, i, j, s);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>> & board, int index, int Max_len, int x, int y, string s) {
        if(index < Max_len) {
            if(mp[s]) {
                ans.push_back(s);
                return ;
            }
        }
        else
            return ;
        for(int i = 0;i < 4;i++) {
            if(!sign[{x, y}] && x >= 0 && x < row && y >= 0 && y < col) {
                // s += board[x][y];
                sign[{x, y}]++;
                dfs(board, index + 1, Max_len, x + direction[i][0], y + direction[i][1], s + board[x][y]);
                sign[{x, y}]--; 
            }
        }
    }
};

int main() {
    Solution so;
    vector<vector<int>> ans = {{"a","b"}, {"c","d"}};
    vector<string> words = {"abcb"};
    vector<string> arr;
    arr = so.findWords(ans, {"abcb"});
    for(int i = 0;i < arr.size();i++) {
        cout << arr[i] << endl;
    }
    return 0;
}