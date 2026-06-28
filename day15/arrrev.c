#include<stdio.h>
int main(){
int i,n,arr[100],rev[100];
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++)
rev[i]=arr[n-1-i];
printf("reversed array: ");
for(i=0;i<n;i++)
printf("%d ",rev[i]);
return 0;}