#include<stdio.h>
int main(){
int i,n,arr[100],temp;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
temp=arr[n-1];
for(i=n-1;i>0;i--)
arr[i]=arr[i-1];
arr[0]=temp;
printf("after right rotation: ");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;}