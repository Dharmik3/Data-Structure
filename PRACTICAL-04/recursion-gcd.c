#include<stdio.h>
#include<conio.h>

void main()
{
    int a,b;
    printf("Enter two num for finding G.C.D:");
    scanf("%d %d",&a,&b);
    printf("G.C.D. Of two num is %d",gcd(a,b));
}

int gcd(int a,int b)
{

    if (a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}
