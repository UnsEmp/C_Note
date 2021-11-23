#include <cstdio>
#include <cstdbool>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char Number[15];
    int LocationRank;
    int Score;
    int classRoom;
    int Rank;
}Stu[30010];

bool compare(struct Student a,struct Student b);

int main()
{
    int n,k,i,j;
    int sum = 0,cnt = 0;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&k);
        sum += k;
        for(j = cnt;j < sum;j++){
            scanf("%s %d",Stu[j].Number,&Stu[j].Score);
            Stu[j].classRoom = i + 1;
        }
        sort(Stu + cnt,Stu + sum,compare);
        Stu[cnt].LocationRank = 1; 
        for(j = 1 + cnt;j < sum;j++){
            if(Stu[j].Score != Stu[j-1].Score){
                Stu[j].LocationRank = j+1-cnt;
            }
            else{
                Stu[j].LocationRank = Stu[j-1].LocationRank;
            }
        }
        cnt = sum;
    }
    sort(Stu,Stu + sum,compare);
    Stu[0].Rank = 1;
    for(i = 1;i < sum;i++){
        if(Stu[i].Score != Stu[i-1].Score){
            Stu[i].Rank = i+1;
        }
        else{
            Stu[i].Rank = Stu[i-1].Rank;
        }
    }
    printf("%d\n",sum);
    for(i = 0;i < sum;i++){
        printf("%s %d %d %d\n",Stu[i].Number,Stu[i].Rank,Stu[i].classRoom,Stu[i].LocationRank);
    }
}

bool compare(struct Student a,struct Student b)
{
    if(a.Score != b.Score)
    return a.Score > b.Score;
    else
    return strcmp(a.Number,b.Number) < 0;
}