#include <cstdio>
char swap(int score)
{
    char ch;
    switch(score/10)
    {
        case 10:ch = 'A';break;
        case 9:ch = 'A';break;
        case 8:ch = 'B';break;
        case 7:ch = 'C';break;
        case 6:ch = 'D';break;
        default:ch = 'E';
    }
    return ch;
}
int main()
{
    unsigned score;
    while(scanf("%i",&score) != EOF){
        if(score <= 100 && score >= 0){
            printf("%c\n",swap(score));
        }
        else{
            printf("Score is error!\n");
        }
    }
}