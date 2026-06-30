//Write a program to Convert lowercase to uppercase.
#include <stdio.h>
void Upper(char string[]){
    int n=0;
    while(string[n]!='\0'){
        if('a'<=string[n] && string[n]<='z'){
            string[n]+='A'-'a';
        }
        n++;
    }
}
int main(){
    char st[21];
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,21,stdin);
    Upper(st);
    printf("Upper = %s",st);
    return 0;
}