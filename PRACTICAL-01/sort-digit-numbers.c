//sorting number in manner of digits in numbers
#include<stdio.h>
#include<conio.h>
#include<math.h>

//function for counting digits of given numbers
int countDigit(int n)
{
    return log10(n)+1;
}

//driver code
void main()
{
    int arr[5];
     int i,n=5;

    printf("Enter 5 numbers:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    sort(arr,n);

  for(i=0;i<n;i++)
  {
      printf("%d  ",arr[i]);
  }
}

void sort(int arr [],int n){
    int i,j;
for(i=0;i<n;i++)
  {
      for(j=1;j<n-i;j++)
      {
          if(countDigit(arr[j])<countDigit(arr[j-1]))
          {
              int temp=arr[j];
              arr[j]=arr[j-1];
              arr[j-1]=temp;
          }
      }
  }
}
