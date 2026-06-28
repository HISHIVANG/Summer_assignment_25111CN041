#include<stdio.h>
int main(){
int i,n,arr[100];
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("array elements are: ");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;}