#include<stdio.h>
int main(){
int i,j,n,m,a[100],b[100],found;
printf("enter size of first array:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter size of second array:");
scanf("%d",&m);
printf("enter elements:");
for(i=0;i<m;i++)
scanf("%d",&b[i]);
printf("union: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
for(i=0;i<m;i++){
found=0;
for(j=0;j<n;j++)
if(b[i]==a[j])
found=1;
if(found==0)
printf("%d ",b[i]);}
return 0;}