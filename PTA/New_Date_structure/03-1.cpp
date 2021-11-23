#include <cstdio>
#include <cstdlib>
#include <cstdbool>

#define Null -1
#define MAX 10
typedef char ElementType;

struct TNode
{
    ElementType Element;
    int Left;
    int Right;
}T1[MAX],T2[MAX];

typedef int Tree;

Tree CreatBinTree(struct TNode T[]);
bool Isomorphic(Tree R1,Tree R2);

int main()
{
    Tree R1,R2;
    R1 = CreatBinTree(T1);
    R2 = CreatBinTree(T2);
    if( Isomorphic(R1,R2) ){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}

Tree CreatBinTree(struct TNode T[])
{
    int N,i,root;
    scanf("%d",&N);
    getchar();
    char cl,cr;
    int check[MAX];
    if( N ){
        for(i = 0;i < N;i++){
            check[i] = 0;
        }
        for(i = 0;i < N;i++){
            scanf("%c %c %c",&T[i].Element,&cl,&cr);
            getchar();
            if(cl != '-'){
                T[i].Left = cl - '0';
                check[T[i].Left] = 1; 
            }
            else{
                T[i].Left = Null;
            }

            if(cr != '-'){
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else{
                T[i].Right = Null;
            }
        }
    }
    else
    return Null;
    for(i = 0;i < N;i++){
        if( !check[i] ){
            break;
        }
    }
    root = i;
    return root;
}
bool Isomorphic(Tree R1,Tree R2)
{
    if(R1 == Null && R2 == Null)
    return true;
    if((R1 != Null && R2 == Null) || (R1 == Null && R2 != Null))
    return false;
    if(T1[R1].Element != T2[R2].Element)
    return false;
    if((T1[R1].Left == Null) && (T2[R2].Left == Null))
    return Isomorphic(T1[R1].Right,T2[R2].Right);
    if((T1[R1].Right == Null) && (T2[R2].Right == Null))
    return Isomorphic(T1[R1].Left,T2[R2].Left);
    if((T1[R1].Left != Null) && (T2[R2].Left != Null) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
    return (Isomorphic(T1[R1].Left,T2[R2].Left) && Isomorphic(T1[R1].Right,T2[R2].Right));
    else
    return (Isomorphic(T1[R1].Left,T2[R2].Right) && Isomorphic(T1[R1].Right,T2[R2].Left));
}