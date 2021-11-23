#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a,b,c;
    vector<int> arr;
    cin >> a >> b;
    c = a + b;
    if(c < 0){
        cout << '-';
        c = -c;
    }
    do{
        arr.push_back(c%10);
        c /= 10;
    }while(c);
    for(int i = arr.size() - 1;i >= 0;i--){
        cout << arr[i];
        if(i % 3 == 0 && i > 0)
            cout << ',';
    }
    return 0;
}