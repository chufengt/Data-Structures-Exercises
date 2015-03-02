/*
(6) 用字符串模拟手算的方法，实现1000位大数的整数加法和减法（可以的话试着实现乘法和除法）

用字符串数组存储大数，从低位到高位依次进行加/减法并进位/借位
加法：当最高位仍有进位时，增加一位并赋值1
减法：相减之前先比较2数大小，小减大要输出负号；输出时从第一位不为零的数开始
*/


#include<stdio.h>
#include<string.h>
#define MAXN 10000

int A[MAXN],B[MAXN];
int len_a,len_b;


//加法运算：将A B相加的数位放入A中
void Add()
{
    int i,c=0;
    for(i=0;i<((len_a>len_b)? len_a:len_b);i++)
    {
        A[i]=A[i]+B[i]+c;
        if(A[i]>9) {c=1;A[i]%=10;}  //进位控制
        else c=0;
    }
    if(c) {A[i]=1;printf("%d",1);}

    while(i--) printf("%d",A[i]);
    printf("\n");
}


//减法运算：
void Minus()
{
    int i,flag,c=0;

/*比较2个大数：先比较数位，位数相同时依次比较各位*/
    if(len_a>len_b||(len_a==len_b&&memcmp(A,B,sizeof(A))>=0)) flag=1;
    else flag=0;

    for(i=0;i<((len_a>len_b)? len_a:len_b);i++)
    {
        //大减小/小减大两种情况操作流程不同：
        if(flag) A[i]=A[i]-B[i]-c;
        else A[i]=B[i]-A[i]-c;

        if(A[i]<0) {c=1;A[i]+=10;}
        else c=0;
    }

    if(!flag) putchar('-');
    for(;!A[i-1];i--);
    while(i--) printf("%d",A[i]);
    printf("\n");

}


int main(void)
{
    int i;
    char a[MAXN],b[MAXN];
    while(gets(a)&&gets(b))
    {
        len_a=strlen(a);len_b=strlen(b);
        //将输入的字符串反转，使得数值的低位在数组的低位上
        strrev(a);strrev(b);
        memset(A,0,sizeof(A));memset(B,0,sizeof(B));
        for(i=0;i<len_a;i++) A[i]=a[i]-'0';
        for(i=0;i<len_b;i++) B[i]=b[i]-'0';

        Add();
//        Minus();
    }
    return 0;
}
