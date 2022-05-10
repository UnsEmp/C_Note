#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct message
{
    string name;
    char sex;
    string ID;
    int score;
};

bool compare(message a,message b)
{
    if(a.sex != b.sex)
        return a.sex < b.sex;
    else
        return a.score > b.score;
        
}

int main()
{
    int n;
    int flag = 1;
    cin >> n;
    message stu[n];
    for(int i = 0;i < n;i++){
        cin >> stu[i].name >> stu[i].sex >> stu[i].ID >> stu[i].score;
    }
    sort(stu, stu + n,compare);
    if(stu[0].sex == 'F')
        cout << stu[0].name << " " << stu[0].ID << endl;
    else{
        cout << "Absent" << endl;
        flag = 0;
    }
    if(stu[n-1].sex == 'M')
        cout << stu[n-1].name << " " << stu[n-1].ID << endl;
    else{
        cout << "Absent" << endl;
        flag = 0;
    }
    if(flag)
        cout << stu[0].score - stu[n-1].score << endl;
    else
        cout << "NA" << endl;
    return 0;
}