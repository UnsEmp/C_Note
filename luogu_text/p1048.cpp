#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
vector<int> dp(MAX);

int main()
{
    int T, M;
    cin >> T >> M;
    int w[M],v[M];
    for(int i = 0;i < M;i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0;i < M;i++){
        for(int j = T;j >= w[i];j--){
            dp[j] = max(dp[j], dp[j - w[i]] +  v[i]);
        }
    }
    int Max = 0;
    for(int i = 0;i <= T;i++){
        Max = max(Max,dp[i]);
    }
    cout << Max;
    return 0;
}