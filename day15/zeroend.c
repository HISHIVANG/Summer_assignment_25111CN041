#include<stdio.h>
int main(){
int i,j,n,arr[100];
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
j=0;
for(i=0;i<n;i++)
if(arr[i]!=0)
arr[j++]=arr[i];
while(j<n)
arr[j++]=0;
printf("array after moving zeros: ");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;}