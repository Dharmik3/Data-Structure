#include<stdio.h>
#include<conio.h>
#define n 5
int main()
{

    int arr[n],i;
    printf("Enter 5 numbers :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Maximu num in the array is %d\n",maximum(arr,0));
    printf("Sum of the array is %d",sum(arr,0));
}

int maximum(int arr[],int i)
{
    static int max=-1;
    if(i==n)
    return max;
    else{
    if(arr[i]>max)
        max=arr[i];
    maximum(arr,++i);
    }
    return max;
}

int sum(int arr[],int i)
{
    static int s=0;
    if(i==n)
        return s;
    else{
    s=s+arr[i];
    sum(arr,++i);
    }
    return s;
}
