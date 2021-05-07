#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    string ID,start,stop,ID_Max,ID_Min;
    string best = "24:00:00";
    string late = "00:00:00";
    cin >> n;
    while(n--){
        cin >> ID >> start >> stop;
        if(start >= stop)
            continue;
        if(start <= best){
            best = start;
            ID_Max = ID;
        }
        if(stop >= late){
            late = stop;
            ID_Min = ID;
        }
    }
    cout << ID_Max << " " << ID_Min;
    return 0;
}