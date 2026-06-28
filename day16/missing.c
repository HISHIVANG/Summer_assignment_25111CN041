#include<stdio.h>
int main(){
int i,n,arr[100],sum=0,total;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
total=(n+1)*(n+2)/2;
for(i=0;i<n;i++)
sum=sum+arr[i];
printf("missing number is: %d",total-sum);
return 0;}