#include <iostream>
#include <iomanip> 

using namespace std;
const int CLK = 100;
int main()
{
    int start,stop;
    cin >> start >> stop;
    int sum = stop - start;
    if(sum % 100 >= 50){
        sum -= (sum%100);
        sum += 100;
    }
    else{
        sum -= (sum%100);
    }
    sum /= CLK;
    printf("%02d:%02d:%02d",sum/3600,((sum%3600)/60),sum%60);
    return 0;
}