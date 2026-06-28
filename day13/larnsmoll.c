#include<stdio.h>
int main(){
int i,n,arr[100],large,small;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
large=arr[0];
small=arr[0];
for(i=1;i<n;i++){
if(arr[i]>large)
large=arr[i];
if(arr[i]<small)
small=arr[i];}
printf("largest is: %d\n",large);
printf("smallest is: %d",small);
return 0;}