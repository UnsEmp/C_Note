#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode* BinTree;

struct TNode {
    ElementType Date;
    BinTree left;
    BinTree right;
};

int init(); 
void CreatBinTree(BinTree &BT);
void OrderTraversalPrint(BinTree BT);
void InOrderTraversalPrint(BinTree BT);
void PostOrderTraversalPrint(BinTree BT);
void RecursionOrderTraversalPrint(BinTree BT);
void RecursionInOrderTraversalPrint(BinTree BT);
void RecursionPostOrderTraversalPrint(BinTree BT);
int main() {
	system("mode con cols=100 lines=35");
	system("color 0A");
	BinTree BT;
	while( 1 ) {
	    int n = init();
	    switch(n) {
	    	case 0: BT = NULL;printf("请输入树的序列:");CreatBinTree(BT);printf("创建成功！\n");break; 
	    	case 1:printf("迭代先序输出:");OrderTraversalPrint(BT);break;
	    	case 2:printf("迭代中序输出:");InOrderTraversalPrint(BT);break;
	    	case 3:printf("迭代后序输出:");PostOrderTraversalPrint(BT);break;
	    	case 4:printf("递归先序输出:");RecursionOrderTraversalPrint(BT);break;
	    	case 5:printf("递归中序输出:");RecursionInOrderTraversalPrint(BT);break;
	    	case 6:printf("递归后序输出:");RecursionPostOrderTraversalPrint(BT);break;
	    	case 7:exit(0);
		}
printf("\n");
		system("pause");
		system("cls");
	}
    return 0;
}

int init()
    {
    	int n;
    	printf(
        "\n\t|---------------------BuildBinTree------------------------|\t\n"
		"\n\t|_________________________________________________________|\t\n"
		"\t|0:创建一个二叉树                                         |\t\n"
		"\t|1:迭代先序遍历                                           |\t\n"
		"\t|2:迭代中序遍历                                           |\t\n"
		"\t|3:迭代后序遍历                                           |\t\n"
		"\t|4:递归先序遍历                                           |\t\n"
		"\t|5:递归中序遍历                                           |\t\n"
		"\t|6:递归后序遍历                                           |\t\n"
		"\t|7:退出程序                                               |\t\n"
		"\t|                                                         |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
	
	printf("\t请输入你想进行的操作：");
	    while(1) {
	    	scanf("%d", &n);
	    	getchar();
	    	if(n >= 0 && n <= 7) break;
			printf("没有该序号的操作请重新输入！\n"); 
		}
	return n;
}

void OrderTraversalPrint(BinTree BT) {
    BinTree stack[100], T = BT;
    int top = -1;
    while(T || top >= 0) {
        while(T) {
            printf("%c", T->Date);
            stack[++top] = T;
            T = T->left;
        }
        T = stack[top--];
        T = T->right;
    }
}
void InOrderTraversalPrint(BinTree BT) {
    BinTree stack[100], T = BT;
    int top = -1;
    while(T || top >= 0) {
        while(T) {
            stack[++top] = T;
            T = T->left;
        }
        T = stack[top--];
        printf("%c", T->Date);
        T = T->right;
    }
}
void PostOrderTraversalPrint(BinTree BT) {
    BinTree lastVisit = BT;
    BinTree stack[100], T = BT;
    int top = -1;
    while(T || top >= 0) {
        while(T) {
            stack[++top] = T;
            T = T->left;
        }
        T = stack[top];
        if(T->right == NULL || T->right == lastVisit) {
            printf("%c",T->Date);
            top--;
            lastVisit = T;
            T = NULL;
        }
        else {
            T = T->right;
        }
    }
}
void CreatBinTree(BinTree &BT) {
    ElementType Date;
    scanf("%c", &Date);
    if(Date != '#') {
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->left = BT->right = NULL;
        BT->Date = Date;
        CreatBinTree(BT->left);
        CreatBinTree(BT->right);
    }
}
void RecursionOrderTraversalPrint(BinTree BT) {
    if(BT) {
        printf("%c", BT->Date);
        RecursionOrderTraversalPrint(BT->left);
        RecursionOrderTraversalPrint(BT->right);
    }
}
void RecursionInOrderTraversalPrint(BinTree BT) {
    if(BT) {
        RecursionInOrderTraversalPrint(BT->left);
        printf("%c",BT->Date);
        RecursionInOrderTraversalPrint(BT->right);
    }
}
void RecursionPostOrderTraversalPrint(BinTree BT) {
    if(BT) {
        RecursionPostOrderTraversalPrint(BT->left);
        RecursionPostOrderTraversalPrint(BT->right);
        printf("%c",BT->Date);
    }
}
