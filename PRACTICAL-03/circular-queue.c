#include<stdio.h>
#include<conio.h>
#define n 5

int queue[n],front=-1,rear=-1;
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
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }

    else if((rear+1)%n==front)
        printf("\nQueue is full...");

    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}

void Delete()
{
    if(front==-1 && rear==-1)
        printf("\nQueue is empty...");
    else if(front==rear)
        front=rear=-1;
    else
    {
        printf("\n%d",queue[front]);
        front=(front+1)%n;
    }
}

void Display()
{   int i=front;
    if(rear==-1&& front==-1)
      printf("\nQueue is empty...");
    else{
        while(i!=rear)
        {
            printf("%d  ",queue[i]);
            i=(i+1)%n;
        }
        printf("%d",queue[rear]);
    }
}
