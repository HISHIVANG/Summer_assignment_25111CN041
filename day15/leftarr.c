#include<stdio.h>
int main(){
int i,n,arr[100],temp;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
temp=arr[0];
for(i=0;i<n-1;i++)
arr[i]=arr[i+1];
arr[n-1]=temp;
printf("after left rotation: ");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;}