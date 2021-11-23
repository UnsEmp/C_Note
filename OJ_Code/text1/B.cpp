#include <bits/stdc++.h>
using namespace std;


int minSessions(int tasks[], int sessionTime) {
    int task = 0;
    int n = 0, m = 0;
    // return 0;
    sort(tasks, tasks + 10);
    while(task < 10) {
        int count = 0;
        for(int i = 10 - 1;i >= 0;i--) {
            if(count + tasks[i] <= sessionTime && tasks[i] != 0) {
                count += tasks[i];
                tasks[i] = 0;
                task++;
            }
        }
        n++;
    }
    while(task < 10) {
        int count = 0;
        for(int i = 10 - 1;i >= 0;i--) {
            if(count + tasks[i] <= sessionTime && tasks[i] != 0) {
                count += tasks[i];
                tasks[i] = 0;
                task++;
            }
        }
        m++;
    }
    return min(n, m);
    
}


int main()
{
    cout << (1 << 1) << endl;
    int arr[] =  {2,3,3,4,4,4,5,6,7,10};
    cout << minSessions(arr, 12);
    return 0;
}