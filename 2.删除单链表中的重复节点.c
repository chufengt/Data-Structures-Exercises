/*
(2). 删除单链表中的重复节点

思路1：对于链表中的每个节点，遍历比较之后的每个节点并删除重复点
思路2：先对链表进行排序，再删去重复点（减少比较步骤，但排序时间复杂度不低）

*/


#include<stdio.h>

typedef struct node
{
    int date;
    struct node *next;
}List;


List *Delete_Repeat_Node(List *head)
{
    List *p1=head,*p2,*p3;

    while(p1->next!=NULL)
    {
        p2=p1;
        while(p2->next!=NULL)
        {
            /*若找到重复节点，更改前驱指针指向，并释放重复点的空间*/
            if(p1->date==p2->next->date)
            {
                p3=p2->next;
                p2->next=p3->next;
                free(p3);
            }
            else
                p2=p2->next;
        }
        p1=p1->next;
    }
    return head;
}
