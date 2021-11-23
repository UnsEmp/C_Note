#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int Ga,Si,Kn;
    int sum_1,sum_2,sum;
    scanf("%d.%d.%d",&Ga,&Si,&Kn);
    sum_1 = Kn + Si * 29 + Ga * 17 * 29;
    scanf("%d.%d.%d",&Ga,&Si,&Kn);
    sum_2 = Kn + Si * 29 + Ga * 17 * 29;
    sum = sum_2 - sum_1;
    if(sum < 0){
        sum = -sum;
        printf("-");
    }
    printf("%d.%d.%d",sum/(17 * 29),(sum%(17 * 29))/29,(sum%(17 * 29))%29);
    return 0;
}