#include <stdio.h>
int main(){
int a,i=1,pt=1,ppt=0,temp,fb=0;                      
printf("enter the number to obtain nth term of fibonacci series:");
scanf("%d",&a);
 while(i<=a){
 fb = ppt+pt;
 temp=pt;
 pt=fb;
 ppt=temp;
 i++;}
printf(",%d",fb);
return 0;}