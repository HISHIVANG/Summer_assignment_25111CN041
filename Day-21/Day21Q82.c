//Write a program to Reverse a string. 
void rev(char string[]){
    int n=0,t;
    while(string[n]!='\0')n++;n--;
    for(int i = 0;i<n/2+1;i++){
        t = string[n-i];
        string[n-i]=string[i];
        string[i] = t;
    }
}
#include <stdio.h>
int main(){
    char st[21];
    printf("Enter string: ");
    scanf("%s",st);
    //fgets(st,21,stdin);
    rev(st);
    printf("Reverse = %s",st);
    return 0;
}