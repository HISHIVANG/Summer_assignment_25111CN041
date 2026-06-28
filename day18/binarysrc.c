#include<stdio.h>
int main(){
int i,n,arr[100],key,low,high,mid,found=0;
printf("enter size of sorted array:");
scanf("%d",&n);
printf("enter elements in sorted order:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("enter element to search:");
scanf("%d",&key);
low=0;
high=n-1;
while(low<=high){
mid=(low+high)/2;
if(arr[mid]==key){
printf("element found at index: %d",mid);
found=1;
break;}
else if(arr[mid]<key)
low=mid+1;
else
high=mid-1;}
if(found==0)
printf("element not found");
return 0;}