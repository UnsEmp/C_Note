#include <iostream>
using namespace std;
int main() {
    int tmp = 2;
    cout << ~tmp + 1 << endl;
    for(int i = 31;i >= 0;i--) {
        if((tmp >> i) & 1) cout << 1;
        else cout << 0;
    }
    return 0;
}