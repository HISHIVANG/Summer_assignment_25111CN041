#include<stdio.h>
int main(){
int a,r,i=0;
int count = 0;
int arr[24];
printf("enter a number to count the setbits:");
scanf("%d",&a);
for(i=0;a!=0;i++){
arr[i]=a%2;
a=a/2;
if(arr[i]==1){
    count = count + 1;}}
printf("the number of setbits are %d",count);
return 0;}