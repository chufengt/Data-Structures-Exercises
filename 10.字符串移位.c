/*
(10)字符串移位：输入一个字符串s，并输入一个整数n，输出字符串s所有字符往右循环移动n位的结果

循环数组的实现
*/


#include<stdio.h>
#include<string.h>

char str[1000];
int n;

int main(void)
{
    int i,len;

    while(1)
    {

        printf("Please input a string:\n");
        gets(str);
        printf("Please input n:\n");
        scanf("%d",&n);
        getchar();

        len=strlen(str);
        n%=len;

    //用取模运算完成数组的循环，并输出共n-1个字符
        for(i=len-n; i<2*len-n; i++)
            putchar(str[i%len]);

        printf("\n\n");

    }
    return 0;
}
