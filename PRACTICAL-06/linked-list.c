#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>

void insert_first();
void insert_last();
void insert_pos(int pos);
void delete_first();
void Display();
void delete_last();
void delete_elm();
int countNodes();
void reverse();
void create_list();
struct node *concatenate(struct node *, struct node *);
struct node
{
    int info;
    struct node *next;
};
struct node * create_node(int elm);
struct node *first=NULL,*current=NULL;
struct node *first1=NULL,*current1=NULL;
int main()
{

    insert_first();
    insert_pos(2);
    insert_pos(3);
    insert_pos(4);
    insert_last();

    Display(first);
    printf("\n");

   printf("No of nodes %d\n",countNodes());

   reverse();
   Display(first);
   printf("\n");

    create_list();
    Display(concatenate(first,first1));

}

void create_list()
{
    int i;
    first1=create_node(19);
    struct node *prev=NULL;
    for(i=1;i<=5;i++)
    {
        struct node *t=create_node(i*6);
        if(i==1){
        first1->next=t;
        prev=t;
        }
        else{
        prev->next=t;
        prev=t;
        }
    }
    current1=prev;
}
void insert_first()
{
    struct node * t;
    int elm;
    printf("Enter  first element:");
    scanf("%d",&elm);
    t=create_node(elm);
    first=t;
    current=t;
}

void insert_last()
{
    struct node *t,*temp;
    int elm;
    printf("Enter last element:");
    scanf("%d",&elm);
    t=create_node(elm);
    temp=first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=t;
    current=t;
}

void insert_pos(int pos)
{
    int i=1;
    struct node *t,*temp;
    int elm;
    printf("Enter element:");
    scanf("%d",&elm);
    t=create_node(elm);
    temp=first;
    while(i!=pos-1)
    {
        i++;
        temp=temp->next;
    }
    t->next=temp->next;
    temp->next=t;

}

struct node * create_node(int elm)
{
 struct node * t;
 t=(struct node*)malloc(sizeof(struct node));
 t->info=elm;
 t->next=NULL;
 return t;
}

void delete_first()
{
    struct node *t;
    t=first;
    if(first->next==NULL){
        printf("%d ",t->info);
        first=current=NULL;
    free(t);
    }
    else
        {
 printf("%d \n",t->info);
        first=first->next;
        free(t);
        }
}

void delete_last()
{
    struct node *t,*p;
    t=current;
    printf("%d \n",t->info);
    p=first;
    while(p->next!=current)
    {
        p=p->next;
    }
    p->next=NULL;
    current=p;
    free(t);
}
void delete_elm()
{   int n;
    printf("Enter elements you wants to delete:");
    scanf("%d",&n);
    struct node *t,*p;
    t=first;
    while(t->info!=n)
    {
        p=t;
        t=t->next;
    }
    p->next=t->next;
    free(t);
}
void Display(struct node * first)
{
    struct node * t;
    t=first;
        while(t!=NULL)
        {
        printf("%d ",t->info);
        t=t->next;
        }

}

int countNodes()
{
    int count=0;
    struct node * temp=first;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void reverse()
{
    struct node* prev =NULL;
    struct node* current=first;
    struct node * next=NULL;
    while(current!=NULL)
        {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
    }
    first=prev;
}
struct node * concatenate(struct node *head1,struct node * head2)
{
    struct node *p;
    if(head1==NULL)
        return(head2);
    if(head2==NULL)
        return(head1);
    p=head1;
    while(p->next!=NULL)
        p=p->next;
    p->next=head2;
    return head1;
}
