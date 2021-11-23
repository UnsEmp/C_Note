#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    map<pair<int, int>, int> mp;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        queue<pair<int, int>> q;
        pair<int, int> temp;
        temp.first = startRow;
        temp.second = startColumn;
        mp[temp]++;
        int step = 0;
        int count = 0;
        while(!q.empty() && step < maxMove) {
            int len = q.size();
            for(int i = 0;i < len;i++) {
                pair<int, int> ans = q.front();
                q.pop();
                for(int j = 0;j < 4;j++) {
                    int x = ans.first + direction[j][0];
                    int y = ans.second + direction[j][1];
                    if(x >= m || ans.second + y >= n) {
                        count++;
                    }
                    else {
                        temp.first = x;
                        temp.second = y;
                        if(!mp[temp]) {
                            q.push(temp);
                        }
                    }
                }
            }
            step++;
        }
        return count;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        getline(cin, line);
        int maxMove = stringToInteger(line);
        getline(cin, line);
        int startRow = stringToInteger(line);
        getline(cin, line);
        int startColumn = stringToInteger(line);
        
        int ret = Solution().findPaths(m, n, maxMove, startRow, startColumn);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}