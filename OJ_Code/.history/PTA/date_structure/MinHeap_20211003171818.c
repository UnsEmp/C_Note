#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 1000

typedef struct HNode* Heap;
typedef int ElementType;
struct HNode {
    ElementType* Data; /* 存储元素的数组 */
    int Size; /* 堆中当前元素个数 */
    int Capacity; /* 堆的最大容量 */
};

typedef Heap MinHeap;

MinHeap CreateHeap(int MaxSize); /* 创建空的堆，最大容量为MaxSize */
bool IsFull(MinHeap H); /* 判断最小堆 H 是不是已经满了，是返回true，否返回false。 */
bool Insert(MinHeap H, ElementType X); /* 往最小堆中插入元素 X */
bool IsEmpty(MinHeap H); /* 判断最小堆 H 是否为空 */
ElementType DeleteMin(MinHeap H); /* 删除最小堆堆顶的元素，并返回它 */

int main() {
    return 0;
}
