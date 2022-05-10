#include <bits/stdc++.h>
using namespace std;

#define IN 10000

bool  compare(pair<double, int> & a, pair<double, int> & b)
{
    return a.second < b.second;
}

int main()
{
    int Distance,Unit,Platform,MaxAction;
    double Capacity;
    cin >> Capacity >> Distance >> Unit >> Platform;
    vector<pair<double, int>> num(Platform + 1);
    for(int i = 0;i < Platform;i++){
        cin >> num[i].first >> num[i].second;
    }
    num[Platform].first = 0;
    num[Platform].second = Distance;
    sort(num.begin(), num.end(), compare);
    if(num[0].second != 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    MaxAction = Capacity * Unit;
    int temp,NowDistance = 0,NowPlatform = 0,Tank = 0;
    double need = 0,PriceMin,StopDistance = 0;
    bool flag = true;
    pair<double, int> min;

    while(NowPlatform < Platform){
        int i,temp;
        PriceMin = IN;
        for(i = NowPlatform + 1;i <= Platform;i++){
            if(num[i].second <= NowDistance + MaxAction){
                if(num[NowPlatform].first > num[i].first){
                    if((num[i].second - num[NowPlatform].second) >= Tank){
                        Tank = num[i].second - num[NowPlatform].second - Tank;
                        need += (double)(Tank) / Unit * num[NowPlatform].first;
                        Tank = 0;
                    }
                    else{
                        Tank =  Tank - (num[i].second - num[NowPlatform].second);
                    }

                    NowDistance = num[i].second;
                    NowPlatform = i;
                    break;
                }
                else if(num[i].first < PriceMin){
                    PriceMin = num[i].first;
                    temp = i;
                }
            }
            else{
                if(PriceMin != IN){
                    need += (double)(MaxAction - Tank) / Unit * num[NowPlatform].first;
                    Tank = MaxAction - (num[temp].second - num[NowPlatform].second);
                    NowDistance = num[temp].second;
                    NowPlatform = temp;
                    break;
                }
                else{
                    StopDistance = num[NowPlatform].second + MaxAction;
                    printf("The maximum travel distance = %.2lf",StopDistance);
                    return 0;
                }
            }

        }
    }
    printf("%.2lf",need);
    return 0;
}