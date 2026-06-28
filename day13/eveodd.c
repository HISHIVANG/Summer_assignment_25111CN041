#include<stdio.h>
int main(){
int i,n,arr[100],even=0,odd=0;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++){
if(arr[i]%2==0)
even++;
else
odd++;}
printf("even count: %d\n",even);
printf("odd count: %d",odd);
return 0;}