//Insertion and deletion in desired array

#include<stdio.h>
#include<conio.h>
#define n 5
int arr[n+1];
void main()
{
    int index,value,i;

    printf("\nEnter your %d number:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\nyour entered number\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    printf("Enter position for Inserting number:");
    scanf("%d",&index);
    printf("Enter value: ");
    scanf("%d",&value);
    if(index<0||index>n){
    printf("Invalid index!");
        exit(0);
}
    insert(index,value);

    printf("\nAfter Inserting...\n");
    for(i=0;i<=n;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    int pos;
    printf("\nEnter position for delete the number:");
    scanf("%d",&pos);
    if(pos>n||pos<0){
        printf("Invalid deletion index!");
        exit(0);
        }
    Delete(pos);
    printf("\nAfter Deletion...\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }

}

//insert function at desired position
//take two input index number and value

void insert(int index,int value)
{

int j;
for(j=n;j>index;j--)
{
    arr[j]=arr[j-1];
}
arr[j]=value;
}


//deletion function
void Delete(int pos)
{   int i;

    for(i=pos;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
}
