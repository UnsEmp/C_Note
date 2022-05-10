#include <stdio.h>
#define MAX 101

struct student {
    char name[25];
    int average;
    int score;
    char minister;
    char west;
    int word;
    int sum = 0; //该学生的奖学金总数
};

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0, Max = -1, sign = 0;
    struct student stu[MAX];
    for(int i = 0;i < n;i++) {
        scanf("%s %d %d %c %c %d", stu[i].name, &stu[i].average, &stu[i].score, &stu[i].minister, &stu[i].west, &stu[i].word);
        stu[i].sum = 0;
        if(stu[i].average > 80 && stu[i].word > 0) stu[i].sum += 8000;
        if(stu[i].average > 85 && stu[i].score > 80) stu[i].sum += 4000;
        if(stu[i].average > 90) stu[i].sum += 2000;
        if(stu[i].average > 85 && stu[i].west == 'Y') stu[i].sum += 1000;
        if(stu[i].score > 80 && stu[i].minister == 'Y') stu[i].sum += 850;
        if(stu[i].sum > Max) {
            Max = stu[i].sum;
            sign = i;
        }
        sum += stu[i].sum;
    }
    printf("%s\n%d\n%d", stu[sign].name, stu[sign].sum, sum);
    return 0;
}