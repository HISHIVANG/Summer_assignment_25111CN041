//Write a program to Check string rotation.
#include <stdio.h>
int what(char st[],char ts[]){
    int n = 0;
    int r = 0;
    while(st[n]!='\0'&&st[n]!='\n') n++;
    while(ts[r]!='\0'&&ts[r]!='\n') r++;
    if(n!=r) return -1;
    char doublelist[2*n+1];doublelist[2*n] = '\0';
    for(int i = 0;i<n;i++){
        doublelist[i] =doublelist[i+n]= st[i];  
    }
    int matched = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(doublelist[i+j]!=ts[j]){
                matched = 0;
                break;
            }
            matched = 1;
        }
        if(matched){
            return i;
        }
    }
    return -1;
}
int main(){
    int size = 20 +1;
    char st[size];
    char ts[size];
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    printf("Enter string: ");
    fgets(ts,size,stdin);
    int c = what(st,ts);
    if(c<0){
        printf("No rotation matched");
    }
    else{
        printf("Rotation difference = %d",c);
    }
    return 0;
}
