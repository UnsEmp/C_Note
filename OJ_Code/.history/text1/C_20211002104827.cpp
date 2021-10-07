#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    cout << (1 << 31);
    return 0;
    string s = "10000001";
    bitset<8> foo (string("10000001"));
    foo.flip();
    cout << foo << endl;
    return 0;
}