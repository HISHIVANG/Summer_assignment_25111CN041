#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int menu(char **str, size_t *size);
void setsize(char **str, size_t *size);
void enterstring(char **str, size_t *size);
void display(char **str, size_t *size);
void setchar(char **str, size_t *size);
void replacechar(char **str, size_t *size);
void give_length(char **str, size_t *size);
void touppercase(char **str, size_t *size);
void tolowercase(char **str, size_t *size);
void reverse(char **str, size_t *size);
void flush();
void hold();

int main(){
    size_t size = 32;
    char *str = (char*)calloc(size, sizeof(char));
    while(1){
        int c = menu(&str, &size);
        if(c == 1) setsize(&str, &size);
        else if(c == 2) enterstring(&str, &size);
        else if(c == 3) setchar(&str, &size);
        else if(c == 4) replacechar(&str, &size);
        else if(c == 5) give_length(&str, &size);
        else if(c == 6) touppercase(&str, &size);
        else if(c == 7) tolowercase(&str, &size);
        else if(c == 8) reverse(&str, &size);
        else if(c == 9) break;
    }
    free(str);
    return 0;
}

void flush(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void hold(){
    printf("\nEnter any key to continue. ");
    scanf(" %c", &(char){0});
}

void display(char **str, size_t *size){
    printf("Str = \"%s\"\n", *str);
}

void setsize(char **str, size_t *size){
    size_t i;
    printf("\033cEnter new size: ");
    if(scanf(" %zu", &i) != 1){
        printf("Error");
        sleep(1);
        return;
    }
    char *temp = realloc(*str, i * sizeof(char));
    if(temp == NULL){
        printf("Error");
        sleep(1);
        return;
    }
    *str = temp;
    *size = i;
}

void enterstring(char **str, size_t *size){
    printf("\033c");
    display(str, size);
    printf("Enter string: ");
    //flush();
    fgets(*str, *size, stdin);
    // remove trailing newline
    size_t len = strlen(*str);
    if(len > 0 && (*str)[len-1] == '\n')
        (*str)[len-1] = '\0';
}

void setchar(char **str, size_t *size){
    int i = 0;
    char c = 0;
    size_t len = strlen(*str);
    printf("\033c");
    display(str, size);
    printf("Enter position: ");
    if(scanf(" %d", &i) != 1){
        printf("Error");
        sleep(1);
        return;
    }
    if(i < 1 || i > len){
        printf("Exiting...");
        sleep(1);
        return;
    }
    printf("Enter char: ");
    if(scanf(" %c", &c) != 1){
        printf("Error");
        sleep(1);
        return;
    }
    (*str)[i-1] = c;
}

void replacechar(char **str, size_t *size){
    int i = 0, j = 0;
    size_t len = strlen(*str);
    printf("\033c");
    display(str, size);
    printf("Enter position i: ");
    if(scanf(" %d", &i) != 1){
        printf("Error");
        sleep(1);
        return;
    }
    if(i < 1 || i > len){
        printf("Exiting...");
        sleep(1);
        return;
    }
    printf("Enter position j: ");
    if(scanf(" %d", &j) != 1){
        printf("Error");
        sleep(1);
        return;
    }
    if(j < 1 || j > len){
        printf("Exiting...");
        sleep(1);
        return;
    }
    if((i--) == (j--)) return;
    char t = (*str)[i];
    printf("\033c");
    display(str, size);
    (*str)[i] = (*str)[j];
    (*str)[j] = t;
    printf("\033c");
    display(str, size);
    sleep(1);
}

void give_length(char **str, size_t *size){
    printf("\033c");
    display(str, size);
    printf("Length = %zu", strlen(*str));
    hold();
}

void touppercase(char **str, size_t *size){
    for(size_t i = 0; i < strlen(*str); i++)
        (*str)[i] = toupper((*str)[i]);
    printf("\033c");
    display(str, size);
    sleep(1);
}

void tolowercase(char **str, size_t *size){
    for(size_t i = 0; i < strlen(*str); i++)
        (*str)[i] = tolower((*str)[i]);
    printf("\033c");
    display(str, size);
    sleep(1);
}

void reverse(char **str, size_t *size){
    size_t len = strlen(*str);
    for(size_t i = 0; i < len/2; i++){
        char t = (*str)[i];
        printf("\033c");
        display(str, size);
        (*str)[i] = (*str)[len-1-i];
        (*str)[len-1-i] = t;
        printf("\033c");
        display(str, size);
        sleep(1);
    }
}

int menu(char **str, size_t *size){
    int c;
    while(1){
        printf("\033c");
        display(str, size);
        printf("String Operator\n");
        printf("1. Set size\n");
        printf("2. Enter string\n");
        printf("3. Set character\n");
        printf("4. Swap characters\n");
        printf("5. Give length\n");
        printf("6. To uppercase\n");
        printf("7. To lowercase\n");
        printf("8. Reverse\n");
        printf("9. Exit\n");
        printf("Choice: ");
        if(scanf("%d", &c) != 1){
            flush();
            continue;
        }
        flush();
        return c;
    }
}