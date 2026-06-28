#include<stdio.h>
int main(){
int i,j,n,m,a[100],b[100];
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
printf("intersection: ");
for(i=0;i<n;i++)
for(j=0;j<m;j++)
if(a[i]==b[j])
printf("%d ",a[i]);
return 0;}