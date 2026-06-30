//Write a program to Count words in a sentence
#include <stdio.h>
int countwords(char string[]){
    int n=0,space = 1,count=0;;
    while(string[n]!='\n' && string[n]!='\0'){
        if(string[n]!=' ' && space==1){
            count++;
            space=0;
        }
        if(string[n]==' ') space = 1;
        n++;
    }
    return count;
}
int main(){
    int size = 40 +1;
    char st[size];
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    printf("words = %d",countwords(st));
    return 0;
}