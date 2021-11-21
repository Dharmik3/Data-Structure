#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node * create_node(int x);
struct node * top=NULL;

struct node * create_node(int x)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->link=NULL;
    return t;
}


void push(int x)
{
    struct node *t=create_node(x);
    t->link=top;
    top=t;
}
int isEmpty()
{
    if(top==NULL)
        return 1;
    return 0;
}
int pop()
{   int x;
    struct node *t;
    if(isEmpty())
    {
        printf("Empty   ");
        exit(0);
    }

    else{
        t=top;
        x=t->data;
        top=top->link;
        free(t);
    }
    return x;
}

int peek()
{
    int x;
    struct node *t;
    if(isEmpty())
    {
        printf("Empty   ");
        exit(0);
    }

    else{
        t=top;
        x=t->data;
    }
    return x;
}
void Display()
{
    if(isEmpty())
    {
         printf("Empty   ");
        exit(0);
    }
    else{
    struct node *t=top;
    while(t!=NULL){
        printf("%d   ",t->data);
            t=t->link;
        }

    }
}

int main()
{

    // Push the elements of stack
    push(11);
    push(22);
    push(33);
    push(44);

    // Display stack elements
    Display();

    // Print top element of stack
    printf("   %d  ",peek());

    // Delete top elements of stack
    pop();
    pop();

    // Display stack elements
    Display();

    // Print top element of stack
    printf("   %d  ",peek());

    return 0;
}


