//INFIX TO PREFIX USING STACK
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define n 100

int tos=-1;
char arr[n];


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

void Push(char x)
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

char Pop()
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
int precedence(char sym)
{
    if(sym=='$')
        return 3;
    else if(sym=='*'||sym=='/')
        return 2;
    else if(sym=='+'||sym=='-')
        return 1;
    else return 0;
}


void infixToPrefix(char infix[],char prefix[])
{

    int i,j;
    char item;
    char x;
    infix=strrev(infix);
    Push(')');
    strcat(infix,"(");
    i=0;
    j=0;
    item=infix[i];

    while(item!='\0')
    {

        if(item==')'){
            Push(item);
        }
        else if(isdigit(item)||isalpha(item))
        {
            prefix[j]=item;
            j++;
        }
        else if(isOperator(item))
        {
            x=Pop();
            while(isOperator(x)==1&&precedence(x)>=precedence(item))
            {
                prefix[j]=x;
                j++;
                x=Pop();
            }
            Push(x);
            Push(item);
        }
        else if(item=='(')
        {
            x=Pop();
            while(x!=')')
            {
                prefix[j]=x;
                j++;
                x=Pop();
            }
        }

        else
        {
            printf("Invalid expression!");  
        exit(1);
        }
        i++;
        item=infix[i];
    }
    prefix[j]='\0';
}
int main()
{
    char infix[n],prefix[n];
    printf("Enter infix expression :");
    gets(infix);
    infixToPrefix(infix,prefix);
    printf("\n Prefix expression :");
    puts(prefix);
}
