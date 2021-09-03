#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL inf = (1LL << 63);

long long TransformTen(vector<int> a,int system)
{
    long long y = 0,product = 1;
    for(int i = a.size() - 1;i >= 0;i--){
        y = y + a[i] * product;
        if(y < 0 || y > inf)
        return -1;
        product *= system;
    }
    return y;
}

bool TransformCompare(long long a,long long b)
{
    if(b < 0)
        return 1;
    if(a > b)
        return -1;
    else if(a == b)
        return 0;
    else
        return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2,s;
    vector<int> N1,N2;
    int tag,radix;
    int Max1 = 0,Max2 = 0;
    cin >> s1 >> s2 >> tag >> radix;
    if(tag == 2){
        s = s1;
        s1 = s2;
        s2 = s;
    }
    for(int i = 0,j = 0;i < s1.size() || j < s2.size();i++,j++){
        if(i < s1.size()){
            if(s1[i] >= '0' && s1[i] <= '9'){
                N1.emplace_back(s1[i] - '0');
                // if((s1[i] - '0') > Max1)
                //     Max1 = s1[i] - '0' + 1; //进制数至少比每个位上的大 1；
            }
            else{
                N1.emplace_back(s1[i] - 'a' + 10);
                // if((s1[i] - 'a' + 10) > Max1)
                //     Max1 = s1[i] - 'a' + 10 + 1;
            }
        }
        if(j < s2.size()){
            if(s2[j] >= '0' && s2[j] <= '9'){
                N2.emplace_back(s2[j] - '0');
                if((s2[j] - '0') > Max2)
                    Max2 = s2[j] - '0' + 1;
            }
            else{
                N2.emplace_back(s2[j] - 'a' + 10);
                if((s2[j] - 'a' + 10) > Max2)
                    Max2 = s2[j] - 'a' + 10 + 1;
            }
        }

    }
    long long temp,temp1,temp2;
    temp1 = TransformTen(N1,radix);
    temp = temp1;
    while(temp){
        if(Max1 < temp%10)
            Max1 = temp%10 + 1;
        temp /= 10;
    }
    int left = Max2,right = Max2 + Max1 + 1,mid;
    while(left <= right){
        mid = (right + left) / 2;
        if(TransformCompare(temp1,TransformTen(N2,mid)) == 1){
            right = mid - 1;
        }
        else if(TransformCompare(temp1,TransformTen(N2,mid)) == -1){
            left = mid + 1;
        }
        else{
            cout << mid << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;

    return 0;
}