#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double x, y, x1, y1, sum;
    x1 = 100;
    y1 = 10;
    cin >> x >> y;
    sum = pow((x1 - x), 2) + pow((y1 - y), 2);
    sum = sqrt(sum);
    sum -= 10;
    if(sum >= 0) {
        printf("%.3lf\n", sum);
    }
    else {
        printf("0\n");
    }
    return 0;
}