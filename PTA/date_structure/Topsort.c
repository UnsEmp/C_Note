#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef struct ENode* PtrToENode;
struct ENode {
    Vertex V1, V2;
    WeightType W;
};

typedef PtrToENode Edge;
typedef struct AdjVNode* PtrToAdjNode;
struct AdjVNode {
    Vertex AdjV;
    WeightType weight;
    PtrToAdjNode Next;
};

typedef struct VNode {
    PtrToAdjNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];

typedef struct GNode* PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreatLGraph(int VertexNum) {
    Vertex V;
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = Vertex;
    Graph->Ne = 0;
    for(V = 0;V < Graph->Nv;V++) {
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E) {
    PtrToAdjNode NewNode;
    NewNode = (PtrToAdjNode)malloc(sizeof(struct AdjNode));
    NewNode->AdjV = E->V2;
    NewNode->weight = E->W;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
    /*若是无向图下面还需插入一个节点到V2->V1*/    
}

LGraph BuildGraph() {
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    printf("输入顶点的总个数:\n");
    scanf("%d", &Nv);
    Graph = CreatLGraph(Nv);
    Graph->Nv = Nv;
    printf("输入边的个数:\n");
    scanf("%d", &Graph->Ne);
    if(Graph->Ne != 0) {
        Edge E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0;i < Graph->Ne;i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->W);
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

bool TopSort(LGraph Graph, Vertex TopOrder) {
    
}
