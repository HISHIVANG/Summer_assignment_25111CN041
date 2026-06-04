#include<stdio.h>
int main(){
int a,power,j,i,res=1;
printf("enter the base number:");
scanf("%d",&a);
printf("enter the power:");
scanf("%d",&power);
for(i=1;i<=power;i++){
  res=res*a;}
  printf("the answer is:%d",res);
  return 0;
}