//POSTFIX  EXPRESSION
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define n 100

int tos=-1;
int arr[n];

int isFull()
{
    if(tos==sizeof(arr)/sizeof(arr[0])-1)
       {

       return 1;
       }
    else
        return 0;
}

int isEmpty()

{
    if(tos==-1)
        return 1;
    else
        return 0;
}

void Push(int x)
{
    if(isFull())
    {
        printf("Stack is full..!");
        getch();
    }
    else{
        tos++;
        arr[tos]=x;
    }
}

int Pop()
{
    if(isEmpty())
    {
        printf("Stack is empty...");
       return -1;
    }
    else
    {
        return arr[tos--];
    }
}
int isOperator(char sym)
{
    if(sym=='$'||sym=='*'||sym=='/'||sym=='+'||sym=='-')
        return 1;
    return 0;
}
int calculateResult(int op1,int op2,char ope)
{

    if(ope=='+')
        return op1+op2;
    else if(ope=='-')
        return op1-op2;
    else if(ope=='*')
        return op1*op2;
    else if(ope=='/')
        return op1/op2;
    else if(ope=='$')
        return (int)pow(op1,op2);
}
void postfixEvaluation(char postfix[])
{

    int result;
    int op1;
    int op2;
    char item;
    int i;
    i=0;
    item=postfix[i];

    while(item!='\0')
    {

        if(isdigit(item)){
            Push(item-48);
        }
        else
        {
            op2=Pop();
            op1=Pop();
            result=calculateResult(op1,op2,item);
            Push(result);

        }
        i++;
        item=postfix[i];
    }

}


void main()
{
    char postfix[n];
    int i;
    printf("Enter postfix expression :");
    scanf("%s",postfix);
    postfixEvaluation(postfix);

        printf(" Answer is %d",Pop());
}

