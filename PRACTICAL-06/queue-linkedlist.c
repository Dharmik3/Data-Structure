#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * rear=NULL;
struct node *front=NULL;
struct node * create_node(int x)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    return t;
}
void push(int x)
{
    struct node *t=create_node(x);
    if(front==NULL)
    {
    front=t;
    rear=t;
    }
    else{
        struct node *p=front;
    while(p->next!=NULL)
        p=p->next;
    rear=t;
    p->next=t;
    }
}

int isEmpty()
{
    if(front==NULL||front>rear)
        return 1;
    return 0;
}
 void pop()
 {
     struct node  *t;
     if(isEmpty())
        printf("Empty   ");
     else{
        t=front;
        front=t->next;
        free(t);
     }
 }

void Display()
{
    if(isEmpty())
        printf("Empty  ");

    else
    {

        struct node *t=front;
        while(t!=NULL)
        {
            printf("%d  ",t->data);
            t=t->next;
        }
    }
}

int main()
{

    // Push the elements of
    push(11);
    push(22);
    push(33);
    push(44);

    // Display elements
    Display();

    // Delete top elements of
    pop();
    pop();

    // Display elements
    Display();

    return 0;
}
