#include <iostream>
#include <map>
#include <utility>
using namespace std;
int main()
{
    pair<int,int> a;
    pair<int,int> b;
    int n,count1 = 0,count2 = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a.first >> a.second >> b.first >> b.second;
        if((a.first + b.first) == a.second && (a.first + b.first) != b.second){
            count2++;
        }
        else if((a.first + b.first) == b.second && (a.first + b.first) != a.second){
            count1++;
        }
    }
    cout << count1 << " " << count2;
    return 0;
}