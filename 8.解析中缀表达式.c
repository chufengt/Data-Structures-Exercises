/*
(8)解析中缀表达式

先用栈将中缀表达式转化为后缀形式，再用栈计算后缀表达式
*/


#include<stdio.h>
#include<string.h>

//分别存储中缀和后缀表达式(字符串形式)
char Infix[100];
char Postfix[100];

//两栈分别用来存储运算符(转换)和数字(计算)
typedef struct
{
    char operation[100];
    int topofstack;
} Stack_operator;

typedef struct
{
    int number[100];
    int topofstack;
} Stack_number;

Stack_operator A;
Stack_number B;

//初始化两个数组栈
void Init_Stack()
{
    memset(A.operation,0,sizeof(A.operation));
    memset(B.number,0,sizeof(B.number));
    A.topofstack=-1;
    B.topofstack=-1;
}

void Push_A(char x) {A.operation[++(A.topofstack)]=x;}
void Push_B(int x) {B.number[++(B.topofstack)]=x;}

char Pop_A() {return A.operation[(A.topofstack)--];}
int Pop_B() {return B.number[(B.topofstack)--];}

//定义运算符的优先级
int Operator_Order(char c)
{
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='(') return 3;
}


//将中缀表达式转换为后缀表达式
void Infix_to_Postfix()
{
    int count=0;
    int i,ok=0;
    char t;

    for(i=0; Infix[i]; i++)
    {
        //将数字从字符串中提取出来，并用空格分隔数字和符号
        if(!ok&&(Infix[i]>='0'&&Infix[i]<='9'))
        {
            ok=1;
            Postfix[count++]=Infix[i];
        }
        else if(ok&&('0'<=Infix[i]&&Infix[i]<='9')) Postfix[count++]=Infix[i];
        else if(Infix[i]>='('&&Infix[i]<='/') //借助ascii值来判别是否为运算符
        {
            if(ok)  {Postfix[count++]=' ';ok=0;}

            //对运算符号进行比较：
            if(Infix[i]==')')
            {
                while(A.operation[A.topofstack]!='(')
                {
                    Postfix[count++]=Pop_A();
                    Postfix[count++]=' ';
                }
                t=Pop_A();
            }
            else
            {
                while(A.topofstack!=-1&&Operator_Order(A.operation[A.topofstack])>=Operator_Order(Infix[i])&&A.operation[A.topofstack]!='(')
                {
                    Postfix[count++]=Pop_A();
                    Postfix[count++]=' ';
                }
                Push_A(Infix[i]);
            }

        }
    }

    while(A.topofstack!=-1)
    {
        Postfix[count++]=' ';
        Postfix[count++]=Pop_A();
    }
}


//计算后缀表达式
void Calculate()
{
    int result=0,num,a,b;
    char *temp;

    temp=strtok(Postfix," ");
    do
    {
        if(!(temp[0]>='('&&temp[0]<='/'))
        {
            sscanf(temp,"%d",&num);
            Push_B(num);
        }
        else
        {
            a=Pop_B();b=Pop_B();
            switch (temp[0])
            {
                case '+':result=a+b;break;
                case '-':result=b-a;break;
                case '*':result=a*b;break;
                case '/':result=b/a;break;
            }
            Push_B(result);
        }
        temp=strtok(NULL," ");
    }while(temp);

    result=Pop_B();

    if(B.topofstack==-1) printf("%d\n",result);
    else printf("Error!");
}


int main(void)
{
    int i;
    gets(Infix);

    Init_Stack();

    Infix_to_Postfix();

    Calculate();

    return 0;
}

