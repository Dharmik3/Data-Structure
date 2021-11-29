#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct tree *left, *right;
};

struct node *root = NULL;

struct node * create_node(int n)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->left = NULL;
    t->right = NULL;
    t->data = n;
    return t;
}

void setLeft(struct node* p,int n)
{
    struct node *t = create_node(n);
    p->left = t;
}

void setRight(struct node* p,int n)
{
    struct node *t = create_node(n);
    p->right = t;
}


int main()
{
    int n;
    struct node *p,*q;
    printf("Enter data for root node:");
    scanf("%d", &n);
    root = create_node(n);
    while(1)
    {
        printf("Enter data:");
        scanf("%d", &n);
        if(n==-1)
            break;
        p = q = root;
        
        while(p!=NULL)
        {
            q = p;
            if (n < p->data)
                p = p->left;
            else
                p = p->right;
        }
        if(n<q->data)
            setLeft(q, n);
            else
             setRight(q, n);
    }
    return 0;
}