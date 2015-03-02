/*
(4) 将两个有序数组进行合并并排序，要求时间复杂度不得超过O(n2)不能使用冒泡法

对两有序数组元素一一比较，较小的放入新数组中；当某一数组比较完后，将另一数组所有元素放入目标数组
*/


#include<stdio.h>
#define MAXN 10000

int Array[MAXN],a[MAXN],b[MAXN];

//只能在编译时获取数组大小，不能定义在子函数中
int len_a=sizeof(a)/sizeof(int),len_b=sizeof(b)/sizeof(int);

void Combine_Array(int a[],int b[])
{
    int i=0,j=0;
    while(i<len_a&&j<len_b)
    {
        if(a[i]<=b[j])
            {Array[i+j]=a[i]; i++;}
        else
            {Array[i+j]=b[j];j++;}
    }

    //某一数组比较完后
    while(i<len_a)
        {Array[i+j]=a[i];i++;}
    while(j<len_b)
        {Array[i+j]=b[j];j++;}

}
