#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int x = 0;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "X++") x++;
        else if(s == "++X") x++;
        else if(s == "X--") x--;
        else if(s == "--X") x--;
    }
    cout << x << endl;
    return 0;
}