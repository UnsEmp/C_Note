#include <cstdio>
#include <cstdbool>
#include <algorithm>
using namespace std;

struct Price
{
    double sum;
    double sumprice;
    double unitprice;
};
bool compare(struct Price a,struct Price b)
{
    return a.unitprice < b.unitprice;
}
int main()
{
    int N,D;
    scanf("%d %d",&N,&D);
    struct Price P[N];
    for(int i = 0;i < N;i++){
        scanf("%lf",&P[i].sum);
    }
    for(int i = 0;i < N;i++){
        scanf("%lf",&P[i].sumprice);
    }
    for(int i = 0;i < N;i++){
        P[i].unitprice = P[i].sumprice/P[i].sum;
    }
    sort(P,P + N,compare);
    double money = 0;
    for(int i = N-1;i >= 0;i--){
        if(D > P[i].sum){
            money += P[i].sumprice;
            D -= P[i].sum;
        }
        else if(D < P[i].sum){
            money += D * P[i].unitprice;
            break;
        }
        else{
            money += P[i].sumprice;
            break;
        }
    }
    printf("%.2lf",money);
    return 0;
}