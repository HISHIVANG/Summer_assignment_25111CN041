//Write a program to Find common characters in strings.
#include <stdio.h>

int common(char st[],char ts[],char com[]){
    int n =0;
    int write = 0;
    com[0]='\0';
    while (st[n]!='\0'){
        if(st[n]=='\n') goto next;
        int i =0;
        while (com[i]!='\0'){
            if(com[i++]==st[n]){
                goto next;
            }
        }
        i =0;
        while (ts[i]!='\0'){
            if(ts[i++]==st[n]){
                com[write++]=st[n];
                com[write] = '\0';
                goto next;
            }
        }
        next:
        n++;
    }
    
}
int main(){
    int size = 20 +1;
    char st[size],c;
    char ts[size];
    char com[size];
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    printf("Enter string: ");
    fgets(ts,size,stdin);
    common(st,ts,com);
    printf("common = %s",com);
    return 0;
}

