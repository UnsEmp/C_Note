#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAX];

SetName find(SetType S,ElementType X);
void Union(SetType S, SetName root1, SetName root2);
void Initialize(SetType S);
void CheckConect(SetType S, SetName root1, SetName root2);
void Stop(SetType S);

int main() {
    int n;
    SetType S;
    Initialize(S);
    printf("%d", S[1]);
    return 0;
    // scanf("%d", &n);
    // char in;
    // do {
    //     scanf("%c", &in);
    //     switch(in) {
    //         case 'I':Union();break;
    //         case 'C':Check_NetWork();break;
    //         case 'S':Stop();break;
    //     }
    // }while(in != 'S');
    return 0;
}

void Initialize(SetType S) {
    SetType S;
    for(int i = 0;i < MAX;i++) S[i] = -1;
    return S;
}
