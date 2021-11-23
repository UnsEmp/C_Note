#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<double> arr(2010);
int main()
{
    int n,index; //指数
    pair<vector<int>, vector<double>> Ploy; //用来存储第一个多项式
    pair<vector<int>, vector<double>> PloySum; //用来存储乘积过后的多项式
    int count = 0; //记录多项式有多少项
    double coeff; //系数
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> index >> coeff;
        Ploy.first.push_back(index);
        Ploy.second.push_back(coeff);
    }
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> index >> coeff;
        for(int j = 0;j < Ploy.first.size();j++){
            PloySum.first.push_back(index + Ploy.first[j]);
            PloySum.second.push_back(coeff * Ploy.second[j]);
        }
    }
    for(int i = 0;i < PloySum.first.size();i++){
        if(arr[PloySum.first[i]] == 0)
            count++;
        arr[PloySum.first[i]] += PloySum.second[i];
        if(arr[PloySum.first[i]] == 0)
            count--;
    }
    if(count != 0){
        printf("%d",count);
        for(int i = 2009;i >= 0;i--){
            if(arr[i] != 0)
                printf(" %d %.1lf",i,arr[i]);
        }
    }
    else
        printf("0");
    return 0;
}