#include<stdio.h>

int factorial(int n)
{
    if(n==1||n==0)
        return 1;
    else{
            return n * factorial(n-1);
        }
}
float series(float n)
{
    if (n == 1)
        return 1.0;
    else{
        return (n / factorial(n) + series(n - 2));
    }
}
int main()
{
    printf("%f", series(5));
    return 0;
}