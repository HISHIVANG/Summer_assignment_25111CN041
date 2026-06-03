#include<stdio.h>
#include<math.h>
int main(){
int a,r=0,d,i=0;
printf("enter a number to convert from binary to decimal:");
scanf("%d",&a);
for(i=0;a!=0;i++){
d=a%10;
r=r+(pow(2,i))*d;
a=a/10;}
printf("the decimal conversion is = %d",r);
return 0;
}