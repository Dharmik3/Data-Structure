#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>

int count_nodes();
struct node *head = NULL;
struct node
{
	int data;
	struct node *next,*prev;
};


struct node* create_node()
{
    struct node *t;
    int item;
    t = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value :");  
       scanf("%d",&item);  
        t->data=item; 
    t->next = NULL;
    t->prev = NULL;
    return t;
}

void insertion_beginning()  
{  
   struct node *t,*temp;   
   int item;
   t = create_node();
     
   if(head==NULL)  
   {  
      head = t;  
      t -> next = head;   
      t -> prev = head;   
   }  
   else   
   {  
       temp = head;   
    while(temp -> next != head)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = t;  
    t -> prev = temp;  
    head -> prev = t;  
    t -> next = head;  
    head = t;  
   }  
   printf("\nNode inserted\n");  

}
void insertion_last()  
{  
   struct node *t,*temp;  
   t = create_node();  
       if(head == NULL)  
       {  
           head = t;  
           t -> next = head;   
           t -> prev = head;   
       }  
       else  
       {  
          temp = head;  
          while(temp->next !=head)  
          {  
              temp = temp->next;  
          }  
          temp->next = t;  
          t ->prev=temp;  
          head -> prev = t;  
      t -> next = head;  
        }  
    
     printf("\nnode inserted\n");  
}  

void display()  
{  
    struct node *t;  
    t=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(t -> next != head)  
        {  
          
            printf("%d\n", t -> data);  
            t = t -> next;  
        }  
        printf("%d\n", t -> data);  
    }  
              
}  

void insertion_pos(int pos)
{
 struct node *t,*temp;
 int i=1;
 t = create_node();
 temp = head;
 while (i<pos)
 {
     temp = temp->next;
     i++;
 }
 t->next = temp;
 t->prev = temp->prev;
 temp->prev->next = t;
 temp->prev = t;
 printf("\n node inserted \n");
}
void insert_at_pos(int pos)
{
    if(pos==1)
        insertion_beginning();
    else if(pos==count_nodes()+1)
        insertion_last();
    else
        insertion_pos(pos);
}
int count_nodes()
{
    struct node *t;
    int count = 0;
    t = head;

    while(t->next!=head)
    {
        count++;
        t = t->next;
    }
    count++;
    return count;
}

void delete_at_pos(int pos)
{
    struct node *t,*temp;
     t = head;
    if (head == NULL)
    {
        printf("No node is there!");
        return;
    }
   
    else if (pos == 1)
    {
        if(t->next==head)
            {
                free(t);
                head = NULL;
            }
            else{
                temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                t->next->prev = temp;
                temp->next = t->next;
                head = t->next;
                t->next = NULL;
                t->prev = NULL;
                free(t);
            }
    }
    else if(pos==count_nodes())
    {
        if(count_nodes()==1)
            {
                free(t);
                head = NULL;
            }
            else{
                while (t->next != head){
                    t = t->next;
                }
                t->prev->next = head;
                head->prev = t->prev;
                free(t);
            }
    }
    else{
        int i = 1;
        while(i<pos)
        {
            t = t->next;
            i++;
        }
        t->next->prev = t->prev;
        t->prev->next = t->next;
        free(t);
    }
}

int main()
{
    insert_at_pos(1);
    insert_at_pos(1);
    insert_at_pos(3);
    insert_at_pos(2);
    insert_at_pos(1);
    insert_at_pos(6);
    delete_at_pos(1);
    delete_at_pos(2);
    delete_at_pos(4);
    display();
    return 0;
}
