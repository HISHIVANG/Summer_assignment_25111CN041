//Write a program to Remove duplicate characters.
#include <stdio.h>
void removecdup(char string[]){
    int n = 0;
    while (string[n++]!='\0'){
        int read = n, write = n;
        while(string[read] != '\0'){
            if(string[read] != string[n-1]){
                string[write++] = string[read];
            }
            read++;
        }
        string[write] = '\0';
    }
    
    
}
int main(){
    int size = 40 +1;
    char st[size],c;
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    removecdup(st);
    printf("Sentence = %s",st);
    return 0;
}
