/*
(7)有n个无序的数，从中找出两个数，它们的和为A，如果能找到则返回1，不能则返回0，要求时间复杂度为O(nlogn)；

先对序列进行快速排序(nlogn)，再对每一个元素Xi，二分查找A-Xi是否在序列中(logn)，时间复杂度为nlogn+n*logn=O(nlogn)
*/


#include<stdio.h>
#include<stdlib.h>

int N=10;
int array[]={1,2,3,4,5,6,7,8,9,10};

int cmp(int *a,int *b)
{
    return *a-*b;
}

int Binary_Search(int start,int end,int X)
{
    if(start>end) return 0;
    int mid=start+(end-start)/2;
    if(array[mid]==X) return 1;
    return (array[mid]>X)? Binary_Search(start,mid-1,X):Binary_Search(mid+1,end,X);
}

//查找函数
int Search(int A)
{
    int i;
    for(i=0;i<N;i++)
        {if(Binary_Search(0,N,A-array[i])) return 1;}

    return 0;

}

int main(void)
{
    qsort(array,N,sizeof(array[0]),cmp);
    printf("%d\n",Search(10));
}
