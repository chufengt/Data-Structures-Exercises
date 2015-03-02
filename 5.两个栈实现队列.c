/*
(5) 用两个栈实现一个队列

操作流程：栈A用来存储入队元素，栈B用来完成出队；
          入队时将元素Push进栈A里；
          出队时判断栈B：若栈B为空，则将栈A中所有元素Pop进B中，则栈B的顶部即为出队元素
                         若栈B非空，则直接Pop出栈B顶部的元素
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int array[1000];
    int topofstack;
}Stack;

Stack A,B;
//声明及初始化栈A,B
void Init_Stack(Stack *S)
{
    memset(S->array,0,sizeof(S->array));
    S->topofstack=-1;
}

//栈的push/pop操作：
void Push(Stack *S,int x)
{
    S->array[++(S->topofstack)]=x;
}

int Pop(Stack *S)
{
    return S->array[(S->topofstack)--];
}


//队列的入队/出队操作：
void Enqueue(int x)
{
    Push(&A,x);
}

int Dequeue()
{
    if(B.topofstack!=-1)
        return B.array[B.topofstack--];
    else
    {
        while(A.topofstack)
            Push(&B,Pop(&A));
        Pop(&A);
    }
}


int main(void)
{
    Init_Stack(&A);
    Init_Stack(&B);

    return 0;
}
