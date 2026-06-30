//Write a program to Character frequency.
#include <stdio.h>
int countchar(char string[],char c){
    int n=0,count=0;;
    while(string[n]!='\0'){
        if(string[n]==c) count++;
        n++;
    }
    return count;
}
int main(){
    int size = 40 +1;
    char st[size],c;
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);

    printf("Enter character: ");
    scanf(" %c",&c);
    printf("Frequency = %d",countchar(st,c));
    return 0;
}