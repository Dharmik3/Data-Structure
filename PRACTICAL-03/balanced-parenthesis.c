// CHECK WHETHER BALANCED PARENTHESIS OR NOT
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define n 20

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

void main()
{
    char item,x;
    int i=0;
    char exp[n];
    printf("Enter expression: ");
    gets(exp);

    item=exp[i];

    while(item!='\0')
    {

        if(item=='{'||item=='['||item=='(')
            Push(item);
        else if(item=='}'){
        x=Pop();
            if(x!='{')
            {
                printf("Not balanced!");
                getch();
                exit(1);
            }
        }
        else if(item==')'){
        x=Pop();
            if(x!='(')
            {
                printf("Not balanced!");
                getch();
                exit(1);
            }
        }

        else if(item==']'){
        x=Pop();
            if(x!='[')
            {
                printf("Not balanced!");
                getch();
                exit(1);
            }
        }
        i++;
        item=exp[i];
    }
    printf("\nBalanced!");
}
