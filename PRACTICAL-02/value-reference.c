//call by value call by reference demonstrate
#include<stdio.h>
#include<conio.h>

void main()
{
    int a,b;
printf("Enter two numbers:");
scanf("%d%d",&a,&b);

byValue(a,b);
printf("\nAfter Call by value swapped...");
printf("a=%d  b=%d",a,b);

byReference(&a,&b);
printf("\nAfter Call by reference swapped...");
printf("a=%d  b=%d",a,b);
}

void byValue(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}

void byReference(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
