#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n;
    int part = 0,sum = 0;
    vector<int> Distances(n + 1),A(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> A[i];
        sum += A[i];
        Distances[i] = sum;
    }
    cin >> m;
    int left,right;
    for(int i = 0;i < m;i++){
        cin >> left >> right;
        part = Distances[max(left,right) - 1] - Distances[min(left,right) - 1];
        part < (sum - part) ? cout << part << "\n": cout << sum - part << "\n";
    }
    return 0;
}