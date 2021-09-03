#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int row = board.size();
        int col = board[0].size();
        board[rMove][cMove] = color;
        if(Judge(board, rMove, cMove, row, col, color)) {
            return true;
        }
        else {
            return false;
        }
    }
    bool Judge(vector<vector<char>> & board, int x, int y, int r, int c, char color) {
        bool flag = true;
        int count = 0;
        if(x >= 2) {
            count = 0;
            for(int i = x - 1;i >= 0;i--) {
                if(board[i][y] != color && board[i][y] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[i][y] == color)
                        return true;
                    break;
                }
            }
        }
        if((r - x - 1) >= 2) {
            count = 0;
            for(int i = x + 1;i < r;i++) {
                if(board[i][y] != color && board[i][y] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[i][y] == color)
                        return true;
                    break;
                }
            }
        }
        
        if(y >= 2) {
            count = 0;
            for(int j = y - 1;j >= 0;j--) {
                if(board[x][j] != color && board[x][j] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[x][j] == color)
                        return true;
                    break;
                }
            }
        }
        
        if((c - y - 1) >= 2) {
            count = 0;
            for(int j = y + 1;j < c;j++) {
                if(board[x][j] != color && board[x][j] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[x][j] == color)
                        return true;
                    break;
                }
            }
        }
        if(x >= 2 && y >= 2) {
            count = 0;
            for(int i = x - 1, j = y - 1;i >= 0 && j >= 0;i--, j--) {
                if(board[i][j] != color && board[i][j] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[i][j] == color) {
                        return true;
                    }
                    break;
                }
            }
            
        }
        
        if(x >= 2 && (c - y - 1) >= 2) {
            count = 0;
            for(int i = x - 1, j = y + 1;i >= 0 && j < c;i--, j++) {
                if(board[i][j] != color && board[i][j] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[i][j] == color) {
                        return true;
                    }
                    break;
                }
            }
        }
        
        if((r - x - 1) >= 2 && y >= 2) {
            count = 0;
            for(int i = x + 1, j = y - 1;i < r && j >= 0;i++, j--) {
                if(board[i][j] != color && board[i][j] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[i][j] == color) {
                        return true;
                    }
                    break;
                }
            }
        }
        
        if((r - x - 1) >= 2 && (c - y - 1) >= 2) {
            count = 0;
            for(int i = x + 1, j = y + 1;i < r && j < c;i++, j++) {
                if(board[i][j] != color && board[i][j] != '.') {
                    count++;
                    continue;
                }
                else {
                    if(count > 0 && board[i][j] == color) {
                        return true;
                    }
                    break;
                }
            }
        }
        return false;
    }
};