//array in reverse order
#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[10],i,n=10,*p=arr;
    printf("Enter 10 numbers:\n");
    for(i=0;i<n;i++)
        scanf("%d",p++);
    p--;


//printing in reverse order
    printf("Array in reverse order\n");
    for(i=0;i<n;i++)
    printf("%d  ",*(p--));
}
