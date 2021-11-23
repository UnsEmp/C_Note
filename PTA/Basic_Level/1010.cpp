#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    vector<int> coefficient,index;
    int coe,ind;
    while(scanf("%d %d",&coe,&ind) != EOF){
        if(ind == 0)
            break;
        coefficient.push_back(coe * ind);
        index.push_back(ind - 1);
    }
    if(coefficient.size() == 0){
        cout << "0 0";
        return 0; 
    }
    for(int i = 0;i < coefficient.size();i++){
        cout << coefficient[i] << " " << index[i];
        if(i != coefficient.size() - 1)
            cout << " ";
    }
    return 0;
}