#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<unordered_map<int, int>> arr(n + 1);
        unordered_map<int, int> search;
        for(int i = 0;i < preferences.size();i++) {
            int n = preferences[i].size();
            for(int j = 0;j < n;j++) {
                arr[i][preferences[i][j]] = n - j;
            }
        }
        for(int i = 0;i < pairs.size();i++) {
            search[pairs[i][0]] = pairs[i][1];
            search[pairs[i][1]] = pairs[i][0];
        }
        int count = 0;
        for(int i = 0;i < pairs.size();i++) {
            int left = pairs[i][0];
            int right = pairs[i][1];
            if(preferences[left][0] != right) {
                for(int j = 0;preferences[left][j] != right;j++) {
                    if(arr[preferences[left][j]][left] > arr[preferences[left][j]][search[preferences[left][j]]]) {
                        count++;
                        break;
                    }
                }
            }
            if(preferences[right][0] != left) {
                for(int j = 0;preferences[right][j] != left;j++) {
                    if(arr[preferences[right][j]][right] > arr[preferences[right][j]][search[preferences[right][j]]]) {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};