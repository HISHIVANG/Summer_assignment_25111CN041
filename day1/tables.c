#include <stdio.h>
int main(){
int a,i,table=0;
printf("enter the number to obtain table:");
scanf("%d",&a);
for(i=1;i<=10;i++){
    table = a*i;
    printf("%d x %d =  %d\n",a,i,table);
}

return 0;
}