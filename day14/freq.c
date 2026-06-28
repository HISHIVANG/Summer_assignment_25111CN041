#include<stdio.h>
int main(){
int i,n,arr[100],key,count=0;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("enter element to find frequency:");
scanf("%d",&key);
for(i=0;i<n;i++)
if(arr[i]==key)
count++;
printf("frequency of %d is: %d",key,count);
return 0;}