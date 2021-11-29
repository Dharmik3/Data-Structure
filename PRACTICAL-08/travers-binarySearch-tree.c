#include<stdio.h>
#include "binarysearch-tree.c"
//include binarysearch-tree file only one main function is required 
// so comment out main function in binary-search for traversal-binary-search-tree
void inorder(struct node*t)
{
    if(t==NULL)
        return;
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}
void preorder(struct node*t)
{
    if(t==NULL)
        return;
    printf("%d ", t->data);
    inorder(t->left);
    inorder(t->right);
}
void postorder(struct node*t)
{
    if(t==NULL)
        return;
    inorder(t->left);
    inorder(t->right);
    printf("%d ", t->data);
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
    printf("Inorder...");
    inorder(root);
    printf("\nPreorder...");
    preorder(root);
    printf("\nPostrder...");
    postorder(root);
    return 0;
}
