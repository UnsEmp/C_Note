#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_SIZE 100

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &BT)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')  BT=NULL;
	else
	{
		if(!(BT=(BiTree)malloc(sizeof(BiTNode))))exit(0);
		BT->data=ch;
		CreateBiTree(BT->lchild);
		CreateBiTree(BT->rchild);
	}
}

void PreOrder(BiTree BT)
{
	if(BT!=NULL)
	{
		printf("%c",BT->data);
		PreOrder(BT->lchild);
		PreOrder(BT->rchild);
	}
}

void InOrder(BiTree BT)
{
	if(BT!=NULL)
	{
		InOrder(BT->lchild);
		printf("%c",BT->data);
		InOrder(BT->rchild);
	}
}

void PostOrder(BiTree BT)
{
	if(BT!=NULL)
	{
		PostOrder(BT->lchild);
		PostOrder(BT->rchild);
		printf("%c",BT->data);
	}
}

void NRPreOrder(BiTree BT)
{
	BiTree stack[MAX_TREE_SIZE],p;
	int top;
	if(BT!=NULL)
	{
		top=1;
		stack[top]=BT;
		while(top>0)
		{
			p=stack[top];
			top--;
			printf("%c",p->data);
			if(p->rchild!=NULL)
			{
				top++;
				stack[top]=p->rchild;
			}
			if(p->lchild!=NULL)
			{
				top++;
				stack[top]=p->lchild;
			}
		}
	}
}

void NRInOrder(BiTree BT)
{
	BiTree stack[MAX_TREE_SIZE],p;
	int top=0;
	p=BT;
	do
	{
		while(p!=NULL)
		{
			top++;
			stack[top]=p;
			p=p->lchild;
	    }
	    if(top>0)
	    {
	    	p=stack[top];
	    	top--;
	    	printf("%c",p->data);
	    	p=p->rchild;
		}
	}while(p!=NULL||top>0);
}

void NRPostOrder(BiTree BT)
{
	BiTree stack[MAX_TREE_SIZE],p;
	int tag[MAX_TREE_SIZE];
	int top=0;
	p=BT;
	do
	{
		while(p!=NULL)
		{
			top++;
			stack[top];
			p=p->lchild;
			tag[top]=0;
		}
		if(top>0)
		{
			if(tag[top]==1)
			{
				printf("%c",stack[top]->data);
				top--;
			}
				else
				{
					p=stack[top];
					if(top>0)
					{
						p=p->rchild;
						tag[top]=1;
					}
				}
		}
	}while(p!=NULL||top>0);
}

void menu()
{
	int i;
	system("cls");
	printf("%s","\t\t\t二叉树的建立和遍历\n\n");
	for(i=0;i<80;i++)
	    printf("=");
	putchar('\n');
	printf("\t\t1.创建二叉树\n\n");
	printf("\t\t2.先序遍历（递归）\t3.先序遍历（非递归）\n\n");
	printf("\t\t4.中序遍历（递归）\t5.中序遍历（非递归）\n\n");
	printf("\t\t6.后序遍历（递归）\t7.后序遍历（非递归）\n\n");
	printf("\t\t0.退出\n\n"); 
	for(i=0;i<80;i++)
	    printf("=");
	putchar('\n');
	printf("请输入操作序号：");
	int n;
	scanf("%d",&n);
	BiTree t;
	switch(n){
		case 1:
			CreateBiTree(t);
			break;
		case 2:
			PreOrder(t);
			break;
		case 3:
			InOrder(t);
			break;
		case 4:
			PostOrder(t);
			break;
		case 5:
			NRPreOrder(t);
			break;
		case 6:
			NRInOrder(t);
			break;
		case 7:
			NRPostOrder(t);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("\n序号输入错误，请重新选择");
			break; 
	}
		system("pause");
	 
}

int main()
{
	menu();
}
