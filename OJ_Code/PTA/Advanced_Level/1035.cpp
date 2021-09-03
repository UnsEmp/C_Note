#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s = "10lO";
struct Node
{
    string name;
    string password;
    bool flag = true; 
};
int main()
{
    int n,sum = 0;
    cin >> n;
    Node stu[n];
    for(int i = 0;i < n;i++){
        cin >> stu[i].name >> stu[i].password;
        for(int j = 0;j < stu[i].password.size();j++){
            if(stu[i].password[j] == '1'){
                stu[i].password[j] = '@';
                stu[i].flag = false;
            }
            else if(stu[i].password[j] == '0'){
                stu[i].password[j] = '%';
                stu[i].flag = false;
            }
            else if(stu[i].password[j] == 'l'){
                stu[i].password[j] = 'L';
                stu[i].flag = false;
            }
            else if(stu[i].password[j] == 'O'){
                stu[i].password[j] = 'o';
                stu[i].flag = false;
                }
            }
            if(stu[i].flag == false)
                sum++;
    }
    if(sum > 0){
        cout << sum << endl;
        for(int i = 0;i < n;i++){
            if(stu[i].flag == false)
                cout << stu[i].name << " " << stu[i].password << endl;
        }
    }
    else if(sum == 0){
        if(n > 1)
            cout << "There are " << n << " accounts and no account is modified" << endl;
        else
            cout << "There is " << n << " account and no account is modified" << endl;
    }
    return 0;
}