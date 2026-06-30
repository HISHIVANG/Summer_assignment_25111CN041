//Write a program to Remove spaces from string.
#include <stdio.h>
void removechar(char string[], char c){
    int read = 0, write = 0;
    while(string[read] != '\0'){
        if(string[read] != c){
            string[write++] = string[read];
        }
        read++;
    }
    string[write] = '\0';
}
int main(){
    int size = 40 +1;
    char st[size],c;
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    printf("Enter character to remove: ");
    scanf("%c",&c);
    removechar(st,c);
    printf("Sentence = %s",st);
    return 0;
}
