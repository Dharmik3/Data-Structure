#include<stdio.h>
#include<conio.h>
#define n 5

int que[n];
int rear=-1,front=-1;

void main()
{
int choise;
    while(1)
{
    system("cls");
      printf("1. Insert\n");
       printf("2. Delete\n");
       printf("3. Dispaly\n");
       printf("0. exit\n\n");
       printf("Enter your choise:");
       scanf("%d",&choise);
    int x;
       switch(choise)
       {
           case 1:
               printf("\nEnter number:");
               scanf("%d",&x);
                insert(x);

                break;
           case 2:

               Delete();
                break;
           case 3:
               Display();
            break;
            case 0: exit(0);
            break;
            default:
                printf("Invalid Input!");
        }
    getch();
    }
}


void insert(int x)
{
    if(rear==n-1){
        printf("Queue is Full");
        exit(0);
    }
    else{
        if(front==-1)
            front=0;

        que[++rear]=x;
    }
}
void Delete()
{
    if(front==-1||front>rear)
        printf("Queue is empty");
    else{
        printf("%d ",que[front]);
    front++;
    }
}


void Display()
{
    int i=front;
    if(front==-1&&rear==-1||front>rear)
        printf("Queue is empty");
    else
    {
        while(i<=rear){
            printf("%d ",que[i]);
            i++;
        }
    }
}
