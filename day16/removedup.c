#include<stdio.h>
int main(){
int i,j,k,n,arr[100];
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(arr[i]==arr[j]){
for(k=j;k<n-1;k++)
arr[k]=arr[k+1];
n--;
j--;}
printf("array after removing duplicates: ");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
return 0;}