#include<stdio.h>
int main(){
int a,r,i=0;
int arr[24];
printf("enter a number to convert to binary:");
scanf("%d",&a);
for(i=0;a!=0;i++){
arr[i]=a%2;
a=a/2;}
for(int j=i-1;j>=0;j--){
printf ("%d",arr[j]);
}
return 0;}