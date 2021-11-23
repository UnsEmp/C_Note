#include <iostream>
using namespace std;
using ll = long long ;
using PII = pair<int, int>;

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 0;i < n;i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    int count = 0;
    for(int i = sum + 1;i <= sum + 5;i++) if(i % (n + 1) != 1) count++;
    cout << count << endl;
    return 0;
}