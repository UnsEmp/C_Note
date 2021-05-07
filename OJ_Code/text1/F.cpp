#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>
#include <algorithm>
#include <iostream>
int comp(const void*a,const void*b)//用来做比较的函数。
{
    return *(int*)b - *(int*)a;
}
bool compare(int a,int b)
{
    return a < b;
}
int main()
{
    int arr[] = {832,1796,16328,24274,16816,5404,48437,12679,70001,85148,48227,22223,43021,58667,58053,1388,84051,77970,58506,62516,46051,48862,90745,35325,99358,30289,99745,60645,78509,17172,13923,62272,74946,14345,77705,49321,71913,73964,34531,10404,96380};//乱序的数组。
    int i;
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,n,sizeof(int),comp);
    for(i=0;i<10;i++)//输出排序后的数组
    {
        printf("%d ",arr[i]);
    }
    return 0;
}