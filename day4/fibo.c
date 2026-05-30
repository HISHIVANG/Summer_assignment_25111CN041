#include <stdio.h>
int main(){
int a,i=1,pt=1,ppt=0,temp,fb=0;                      
printf("enter the number of terms of fibonacci series:");
scanf("%d",&a);
printf("the fibonacci series is: \n %d,%d",ppt,pt);
while(i<=a){
 fb = ppt+pt;
 printf(",%d",fb);
 temp=pt;
 pt=fb;
 ppt=temp;
 i++;}
return 0;}