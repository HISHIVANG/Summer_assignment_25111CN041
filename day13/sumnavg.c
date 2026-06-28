#include<stdio.h>
int main(){
int i,n,arr[100],sum=0;
float avg;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++)
sum=sum+arr[i];
avg=(float)sum/n;
printf("sum is: %d\n",sum);
printf("average is: %.2f",avg);
return 0;}