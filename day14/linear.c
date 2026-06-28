#include<stdio.h>
int main(){
int i,n,arr[100],key,found=0;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("enter element to search:");
scanf("%d",&key);
for(i=0;i<n;i++){
if(arr[i]==key){
printf("element found at index: %d",i);
found=1;
break;}}
if(found==0)
printf("element not found");
return 0;}