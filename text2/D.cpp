#include <cstdio>
typedef int ElementType; 
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
Position BinarySearch( List L, ElementType X )
{
    ElementType count = -1;
    ElementType left = 0,might = L->Last;
    ElementType mid = (left + might)/2;
    while(might > left){
        if(X > L->Data[mid]){
            left = mid + 1;
        }
        else if(X < L->Data[mid]){
            might = mid - 1;
        }
        else{
            return mid;        
        }
    }
    return NotFound;
}
List creat()
{
    int n;
    scanf("%d",&n);
    List L;
    for(int i = 0;i < n;i++){
        scanf("%d",&L)
    }
}
int main()
{
    creat();
    BinarySearch();
    return 0;
}