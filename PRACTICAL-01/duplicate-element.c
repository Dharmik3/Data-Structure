//Program of remove duplicate elments in array

#include<stdio.h>
#include<conio.h>

void main()
{
    int n,i,j;
    printf("How many numbers you wants to enter :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter numbers: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                Delete(arr,n,j);
                n--;
                j--;
            }
        }
    }

    printf("\nAfter Duplication filter...\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

//deletion function
void Delete(int arr[],int n,int pos)
{   int i;

    for(i=pos;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
}
