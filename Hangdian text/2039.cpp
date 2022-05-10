#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while( n-- ) {
        double a, b, c;
        cin >> a >> b >> c;
        if((a + b) > c && (a + c) > b && (b + c) > a) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}