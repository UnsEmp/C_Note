#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double sum = 0;
        for(int i = 0;i < brackets.size();++i) {
            int x = brackets[i][0], y = brackets[i][1];
            if(x <= income) {
                if(!i) {
                    sum += 1.0 * x * y / 100;
                }
                else {
                    sum += 1.0 * (x - brackets[i - 1][0]) * y / 100;
                }
            }
            else {
                if(!i) {
                    sum += 1.0 * income * y / 100;
                }
                else {
                    sum += 1.0 * (income - brackets[i - 1][0]) * y / 100;
                }
            }
        }
        return sum;
    }
};