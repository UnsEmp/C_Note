#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<int> arr;
    vector<string> sentence;
    int n,temp;
    cin >> n;
    temp = n;
    do{
        arr.push_back(temp%10);
        temp /= 10;
    }while( temp );
    if(n % 100000000 != 0)
        sentence.push_back("")
    return 0;
}