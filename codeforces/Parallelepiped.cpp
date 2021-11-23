#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ml = max(a, max(b, c));
    for(int i = 1;i <= ml;i++) {
        int l = i, r = ml, j, k;
        int sum = a + b + c;
        while(l <= r) {
            int mid = l + r >> 1;
            j = mid;
            k = (sum - i * j) / (i + j);
            int area = i * i * j * j * k * k;
            if(area > (a * b * c)) r = mid - 1;
            else if(area < (a * b * c)) l = mid + 1;
            else {
                cout << (i + j + k) * 4 << endl;
                return 0;
            }
        }

    }
    return 0;
}