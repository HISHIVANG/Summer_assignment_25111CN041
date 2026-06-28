#include<stdio.h>
int main(){
int i,j,k,n,m,p,a[100],b[100],c[100];
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
printf("enter size of third array:");
scanf("%d",&p);
printf("enter elements:");
for(i=0;i<p;i++)
scanf("%d",&c[i]);
printf("common elements: ");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
for(k=0;k<p;k++)
if(a[i]==b[j] && b[j]==c[k])
printf("%d ",a[i]);
return 0;}