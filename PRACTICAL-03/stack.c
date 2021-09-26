//IMplement stack on array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int tos=-1;
int arr[10];
int main()
{
int choise;
    while(1)
{
    system("cls");
      printf("1. Push\n");
       printf("2. Pop\n");
       printf("3. Peek\n");
       printf("0. exit\n\n");
       printf("Enter your choise:");
       scanf("%d",&choise);
    int x;
       switch(choise)
       {
           case 1:
               printf("\nEnter number:");
               scanf("%d",&x);
                Push(x);

                break;
           case 2:
               x=Pop();
               if(x==-1){
                getch();
                break;
               }
                printf("%d",x);
                getch();
                break;
           case 3:
               x=Peek();
               if(x==-1){
                getch();
                break;
               }
                printf("%d",x);
                getch();
            break;
            case 0: exit(0);
            break;
            default:
                printf("Invalid Input!");
        }

    }
}

int isFull()
{
    if(tos==sizeof(arr)/sizeof(arr[0])-1)
       {
    printf("%d",tos);
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

int Peek()
{
    if(isEmpty()){
    printf("Stack is empty...");
   return -1;
    }
    else
        return(arr[tos]);
}

