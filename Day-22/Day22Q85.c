//Write a program to Check palindrome string.
#include <stdio.h>
int is_palindrome(char string[]){
    int n=0;
    while(string[n]!='\0')n++;
    if(string[n-1]=='\n')n--;
    for(int i = 0;i<n/2;i++){
        if(string[i]!=string[n-i-1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    char st[21];
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,21,stdin);
    if(is_palindrome(st)){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
    return 0;
}