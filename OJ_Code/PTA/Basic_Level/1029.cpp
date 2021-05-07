#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>

#define MAX 100
bool HashTable[MAX] = {false};

int main()
{
    char Arr[MAX],Brr[MAX];
    char cl,cr;
    scanf("%s",Arr);
    scanf("%s",Brr);
    for(int i = 0;i < strlen(Arr);i++){
        int j;
        cl = Arr[i];
        for(j = 0;j < strlen(Brr);j++){
            cr = Brr[j];
            if(cl >= 'a' && cl <= 'z')
            cl -= 32;
            if(cr >= 'a' && cr <= 'z')
            cr -= 32;
            if(cl == cr)
            break;
        }
        if(j == strlen(Brr) && HashTable[cl] == false){
            printf("%c",cl);
            HashTable[cl] = true;
        }
    }
    return 0;
}