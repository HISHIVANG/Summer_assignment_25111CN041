#include<stdio.h>
int main(){
int i,n,arr[100],large,second;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
large=arr[0];
second=arr[0];
for(i=1;i<n;i++)
if(arr[i]>large)
large=arr[i];
for(i=0;i<n;i++)
if(arr[i]>second && arr[i]!=large)
second=arr[i];
printf("second largest is: %d",second);
return 0;}
