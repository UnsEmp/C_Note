#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len1,len2;
    cin >> len1;
    vector<int> ar(len1);
    for(int i = 0;i < len1;i++){
        cin >> ar[i];
    }
    cin >> len2;
    vector<int> cr(len2);
    for(int i = 0;i < len2;i++){
        cin >> cr[i];
    }
    sort(ar.begin(),ar.end(),greater<int>());
    sort(cr.begin(),cr.end(),greater<int>());
    int left,right;
    long long Max = 0;
    for(left = 0,right = 0;left < len1 && right < len2;left++,right++){
        if(ar[left] > 0 && cr[right] > 0){
            Max += ar[left] * cr[right];
        }
        else
            break;
    }
    for(left = len1 - 1,right = len2 - 1;left >= 0 && right >= 0;left--,right-- ){
        if(ar[left] < 0 && cr[right] < 0){
            Max += ar[left] * cr[right];
        }
        else
            break;
    }
    cout << Max << endl;
    return 0;
}