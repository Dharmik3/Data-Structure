#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *first = NULL, *current = NULL;

struct node * create_node(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    t->prev = NULL;
    return t;
}
int count_nodes()
{
    struct node *t;
    t = first;
    int count = 1;
    while(t->next!=NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}
void insert_pos(int pos,int elm)
{
    struct node *t;
        t = create_node(elm);
    if(pos==1)
    {
        if(first==NULL)
            first = current = t;
         else{
                t->next = first;
                first->prev = t;
                first = t;
            }
    }
else if(pos==count_nodes()+1)
{
    current->next = t;
    t->prev = current;
    current = t;
}
    else{
        int i = 1;
        struct node *p = first;
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}

void Display(){
    struct node *t=first;
    char c;
    printf("\nIf you want to display from left side write: L  :");
    scanf("%c", &c);
    if(c=='l'||c=='L')
    {
        t = first;
        while(t!=NULL)
        {
            printf("%d ", t->data);
            t = t->next;
        }
    }
    else{
        t = current;
        while(t!=NULL)
        {
            printf("%d ", t->data);
            t = t->prev;
        }
    }

        // while(t!=NULL)
        // {
        //     printf("%d ", t->data);
        //     t = t->next;
        // }
}

int  delete_pos(int pos)
{   
    struct node *t;
    t = first;
    int i = 1;
    int x;
    if(pos==1)
    {
        x = t->data;
        if(t->next==NULL)
        {
            first = current = NULL;
            free(t);
        }
        else{
        t->next->prev = NULL;
        first = t->next;
        t->next = NULL;
        free(t);
        }
        return x;
    }
    else if(pos==count_nodes())
    {
        t = current;
        x = t->data;
        current = t->prev;
        t->prev->next = NULL;
        t->prev = NULL;
        free(t);
        return x;
    }
    else{
    while(i!=pos){
        t = t->next;
        i++;
    }
    x = t->data;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
    return x;
    }
}
int main()
{
    insert_pos(1,23);
    insert_pos(2,34);
    insert_pos(3,67);
    insert_pos(2,45);
    insert_pos(4,55);
    insert_pos(1,89);
    insert_pos(3,90);
    Display();

    printf("\n\n %d\n", delete_pos(1));
    Display();
    printf("\n\n %d\n", delete_pos(3));
    Display();
    printf("\n\n %d", delete_pos(5));
    Display();
    return 0;
}