//Write a program to Find string length without strlen().
#include <stdio.h>
int len(char string[]){
    int i=0;
    while(string[i]!='\0'&&string[i]!='\n')i++;
    return i;
}
int main(){
    char st[21];
    printf("Enter string: ");
    fgets(st,21,stdin);
    printf("length = %i",len(st));
    return 0;
}