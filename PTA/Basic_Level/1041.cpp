#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

struct Node
{
    string name;
    int a;
    int b;
};

int main(){
    int n;
    cin >> n;
    struct Node Stu[n];
    for(int i = 0;i < n;i++){
        cin >> Stu[i].name >> Stu[i].a >> Stu[i].b;
    }
    int M;
    cin >> M;
    int arr[M];
    for(int i = 0;i < M;i++){
        cin >> arr[i];
    }
    for(int j = 0;j < M;j++){
        for(int i = 0;i < n;i++){
            if(Stu[i].a == arr[j])
            cout << Stu[i].name << " " << Stu[i].b << endl;
        }
    }
    return 0;
}