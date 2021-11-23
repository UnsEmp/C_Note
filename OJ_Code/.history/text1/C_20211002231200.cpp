#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i = 0, j = 0;
        int countT = 0, countF = 0;
        int MaxT_len = 0, MaxF_len = 0;

        while(j < n) {
            if(answerKey[j] == 'T' && j != n - 1) {
                j++;
            }
            else {
                if(answerKey[j] == 'F') countF++;
                if(countF > k) {
                    // if(answerKey[i] == 'F') {
                    //     countF--;
                    // }
                    // i++;
                    while(countF > k) {
                        if(answerKey[i] == 'F') {
                            countF--;
                        }
                        i++;
                    }
                }
                else {
                    MaxT_len = max(MaxT_len, j - i + 1);
                    j++;
                }
            }
        }
        i = j = 0;
        
        while(j < n) {
            if(answerKey[j] == 'F' && j != n - 1) {
                j++;
            }
            else {
                if(answerKey[j] == 'T') countT++;
                if(countT > k) {
                    while(countT > k) {
                        if(answerKey[i] == 'T') countT--;
                        i++;
                    }
                }
                else {
                    MaxF_len = max(MaxF_len, j - i + 1);
                    j++;
                }
                // i++;
            }
        }
        return max(MaxF_len, MaxT_len);
    }
};

int main() {
    Solution so;
    string s = "TTFTTFTT";
    int k = 1;
    cout << so.maxConsecutiveAnswers(s, k);
    return 0;
}