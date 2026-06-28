#include<stdio.h>
int main(){
int i,n,m,a[100],b[100],c[200];
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
for(i=0;i<n;i++)
c[i]=a[i];
for(i=0;i<m;i++)
c[n+i]=b[i];
printf("merged array: ");
for(i=0;i<n+m;i++)
printf("%d ",c[i]);
return 0;}