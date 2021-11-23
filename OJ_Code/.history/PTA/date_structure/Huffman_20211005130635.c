#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct HTNode* HuffmanTree;
struct HTNode {
    ElementType weighted;
    HuffmanTree left;
    HuffmanTree right;
};

