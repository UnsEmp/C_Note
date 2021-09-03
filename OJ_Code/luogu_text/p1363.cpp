#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef int ElementType;
typedef int Position;
typedef struct SNode* PtrToSNode;

#define MAXMATRIXSIZE 100 
#define MAXSTACKSIZE 100

struct Offsets
{
    int Vert;//纵向偏移量
    int Horiz;//横向偏移量
}

struct MazePosition //迷宫中位置结构
{
    int Row;
    int Col;
    int Dir;
};

struct SNode 
{
    struct MazePosition* Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreatStack(int MaxSize);
bool IsFull(Stack S);
bool Push(Stack S, ElementType X);
bool IsEmpty(Stack S);
struct MazePosition Pop(Stack S);
void Path(int Maze[][MAXMATRIXSIZE], int ExitRow, int ExitCol);

int main()
{

    return 0;
}

void path(int Maze[][MAXMATRIXSIZE], int ExitRow, int ExitCol)
{
    struct MazePosition Move[8] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    }
    int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE] = {0};
    Stack S;
    struct MazePosition p;
    S = CreatStack(MAXSTACKSIZE);
    int Row, Col, NextRow, NextCol, Dir;
    bool Found = false;
    p.Row = ExitRow;
    p.Col = ExitCol;
    p.Dir = 0;
    push(S, p);

    while(IsEmpty(S) && !Found){
        p = Pop(S);
        Row = p.Row;
        Col = p.Col;
        Dir = p.Dir;
        if(Dir < 8 && !Found){
            NextRow = Row + Move[Dir].Row;
            NextCol = Col + Move[Dir].Col;
            if(NextRow == 1 && NextCol == 1)
                Found = true;
        }
        else{
            if(!Maze[NextRow][NextCol] && !Mark[NextRow][NextCol]){
                Mark[NextRow][NextCol] = 1;
                p.Row = NextRow;
                p.Col = NextCol;
                p.Dir = Dir + 1;
                Push(S, p);
            }
            else
                Dir++;
        }
        if(Found){
            printf("找到路径");
            while(!IsEmpty(S)){
                p = Pop(S);
                printf("%d %d\n",p.Row, p.Col);
            }
        }
        else
            printf("没找到");
    }
}

Stack CreatStack(int Size)
{
    Stack S;
    S = (Stack)malloc(sizeof(SNode));
    S->Data = (struct MazePosition*)malloc(sizeof(MazePosition) * Size);
    S->MaxSize = Size;
    S->Top = -1;
    return S;
}

bool IsFull(Stack S)
{
    return S->Top == S->MaxSize - 1;
}

bool IsEmpty(Stack S)
{
    return S.Top == -1;
}

bool Pop(Stack S)
{
    if(IsEmpty(S)){
        return false;
    }
    else{
        S.Top--;
        return true;
    }
}

bool Push(Stack S, MazePosition p)
{
    if(IsFull(S))
        return false;
    else{
        S->Data[++S.Top]->Row = p.Row;
        S->Data[S.Top]->Col = p.Col;
        return true;
    }
}