#include <iostream>
#include <algorithm>
using namespace std;
char arr[4] = {"BCJ"};
int jrr[128] = {0};
int yrr[128] = {0};
struct grade
{
    int win = 0;
    int draw = 0;
    int fail = 0;
};
int main()
{
    int n;
    char ch,cr;
    cin >> n;
    struct grade j,y;
    for(int i = 0;i < n;i++){
        cin >> ch >> cr;
        if(ch == 'C'){
            if(cr == 'C'){
                j.draw++;
                y.draw++;
            }
            else if(cr == 'J'){
                j.win++;
                jrr['C']++;
                y.fail++;
            }
            else{
                j.fail++;
                y.win++;
                yrr['B']++;
            }
        }
        else if(ch == 'J'){
            if(cr == 'C'){
                j.fail++;
                y.win++;
                yrr['C']++;
            }
            else if(cr == 'J'){
                j.draw++;
                y.draw++;
            }
            else{
                j.win++;
                jrr['J']++;
                y.fail++;
            }
        }
        else{
            if(cr == 'C'){
                j.win++;
                jrr['B']++;
                y.fail++;
            }
            else if(cr == 'J'){
                j.fail++;
                y.win++;
                yrr['J']++;
            }
            else{
                j.draw++;
                y.draw++;
            }
        }
    }
    int max1 = 0,max2 = 0;
    for(int i = 0;i < 3;i++){
        if(jrr[arr[i]] > max1){
            ch = arr[i];
            max1 = jrr[arr[i]];
        }
        if(yrr[arr[i]] > max2){
            cr = arr[i];
            max2 = yrr[arr[i]];
        }
    }
    cout << j.win << " " << j.draw << " " << j.fail << endl;
    cout << y.win << " " << y.draw << " " << y.fail << endl;
    cout << ch << " " << cr;
    return 0;
}