/*
(3)已知二叉树的前序遍历和中序遍历，求后序遍历

前序遍历确定根节点，中序遍历可以划分左右子树；递归此过程可以还原二叉树，并求出后序遍历
*/


#include<stdio.h>
#include<string.h>
#define N 100

char pre[N],in[N];

//寻找前序遍历中的根节点在中序遍历中的位置，用以划分左右子树
int find(char x)
{
    int i;
    for(i=0;in[i];i++)
        if(in[i]==x) return i;
}

//递归函数求后序：当搜索到叶节点时输出，避免用结构再存储树
char post(int pre_left,int pre_right,int in_left,int in_right)
{
    //节点为空
    if(pre_left>pre_right) return;
    //搜索到叶节点时输出
    if(pre_left==pre_right) {printf("%c",pre[pre_left]);return;}

    int position=find(pre[pre_left]);

    //计算左右子树的长度(节点数)，用以在前序遍历中划分左右子树
    int left_len=position-in_left;
    int right_len=in_right-position;

    post(pre_left+1,pre_left+left_len,in_left,position-1);
    post(pre_left+left_len+1,pre_right,position+1,in_right);

    printf("%c",in[position]);

    return;
}

int main(void)
{
    while(gets(pre)&&gets(in))
    {
        post(0,strlen(pre)-1,0,strlen(in)-1);

        putchar('\n');
    }

    return 0;
}
