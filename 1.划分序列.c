/*
(1). k1到kn，在O(n)复杂度内分为大于ki的部分和小于ki的部分

类似快排的比较方式，逐一判断并移动各个元素(一次只移动一个)
*/


#include<stdio.h>
#define MAXN 1000

int array[MAXN];

/*分割函数*/
void segment(int size,int Ki)
{
    int i=1,j=size,temp;
    int x=array[Ki];
/*先将要求的Ki移动到K1，便于从两端向中间遍历*/
    if(array[Ki]!=array[1]) temp=array[Ki];array[Ki]=array[1];array[1]=temp;

    while(i<j)
    {
        while(array[j]>=x&&i<j) j--;
        if(i<j) array[i++]=array[j];

        while(array[i]<=x&&i<j) i++;
        if(i<j) array[j--]=array[i];
    }

    array[i]=x;

}


int main(void)
{
    int size=0,i,j;
    do
    {
        scanf("%d",&array[++size]);
    }while(getchar()!='\n');

/*获取数组及所要求的Ki */
    scanf("%d",&i);

    segment(size,i);

    for(i=1;i<=size;i++) printf("%d ",array[i]);
    printf("\n");

    return 0;
}
