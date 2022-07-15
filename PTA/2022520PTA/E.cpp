#include <bits/stdc++.h>
using namespace std;

string n, m, a, b;
int arr[10];
bool judge(string a, string b) {
    int tmp[10];
    memset(tmp, 0, sizeof tmp);
    for(int i = 0;i < a.size();++i) tmp[a[i] - '0'] ++;
    for(int i = 0;i < b.size();++i) tmp[b[i] - '0'] ++;
    for(int i = 0;i <= 9;++i) {
        if(arr[i] != tmp[i]) return false;
    }
    return true;
}

int main() {

    cin >> n >> m;
    memset(arr, 0, sizeof arr);
    for(int i = 0;i < n.size();++i) arr[n[i]- '0'] ++;
    for(int i = 0;i < m.size();++i) arr[m[i] - '0'] ++;
    while(1) {
        cin >> a >> b;
        if(a == "0" && b == "0") break;
        if(n[0] == '0' || m[0] == '0') {
            cout << "No" << "\n";
            continue;
        }
        if(a[0] == '0' || b[0] == '0') {
            cout << "No" << "\n";
            continue;
        }
         if(judge(a, b)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}