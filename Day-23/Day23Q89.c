//Write a program to Find first non-repeating character.

#include <stdio.h>
int is_single(char string[],char c){
    int n=0,count=0;;
    while(string[n]!='\0'){
        if(string[n]==c) count++;
        if(count>1) return 0;
        n++;
    }
    return 1;
}
char firstnonrepeating(char s[]){
    int n =0;
    while (s[n]!='\0'){
        if(s[n]=='\n'){n++;continue;}
        if(is_single(s,s[n])){
            return s[n];
        }
        n++;
    }
    return '\0';
}
int main(){
    int size = 20 +1;
    char st[size],c;
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    c = firstnonrepeating(st);
    if(c == '\0')
        printf("No non-repeating character");
    else
        printf("first non-repeating character = %c", c);
    return 0;
}
