#include<stdio.h>
int main(){
int i,j,n,arr[100];
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("duplicate elements are: ");
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(arr[i]==arr[j])
printf("%d ",arr[i]);
return 0;}