#include<stdio.h>
int main(){
int i,j,n,arr[100],temp,minidx;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n-1;i++){
minidx=i;
for(j=i+1;j<n;j++)
if(arr[j]<arr[minidx])
minidx=j;
temp=arr[minidx];
arr[minidx]=arr[i];
arr[i]=temp;}
printf("sorted array: ");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;}