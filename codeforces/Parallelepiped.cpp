#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 1;i <= 10000;i++) {
        for(int j = i;j <= 10000;j++) {
            int x = (int)sqrt((long long)a * b * c) / (i * j);
            if(x > 0 && x <= 10000 && (i * j + i * x + j * x) == (a + b + c) && (i * i * j * j * x * x) == a * b * c) {
                cout << (i + j + x) * 4 << endl;
                return 0;
            }
        }
    }
    return 0;
}