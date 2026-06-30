//Write a program to Create library management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void flush();
int find_book(int id);
void addbook();
void removebook();
void showall();
void show_id();
int menu();

typedef struct book{
    char title[30];
    char author[30];
    int bookid;
    int active;
} book;

book lib[30];

void flush(){
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}

int find_book(int id){
    for(int i=0;i<30;i++){
        if(lib[i].active && lib[i].bookid==id)
            return i;
    }
    return -1;
}

int create(int id, char title[], char author[]){
    for(int i=0;i<30;i++){
        if(!lib[i].active){
            lib[i].bookid = id;
            strcpy(lib[i].title, title);
            strcpy(lib[i].author, author);
            lib[i].active = 1;
            return i;
        }
    }
    return -1;
}

void addbook(){
    char title[30], author[30];
    int id;

    system("cls");

    printf("Enter title: ");
    fgets(title,30,stdin);
    title[strcspn(title,"\n")] = '\0';

    printf("Enter author: ");
    fgets(author,30,stdin);
    author[strcspn(author,"\n")] = '\0';

    printf("Enter book id: ");
    scanf("%d",&id);
    flush();

    if(find_book(id)!=-1){
        printf("Book already exists");
        sleep(1);
        return;
    }

    if(create(id,title,author)==-1){
        printf("Library full");
    } else {
        printf("Book added");
    }

    sleep(1);
}

void removebook(){
    int id;

    system("cls");
    printf("Enter book id to remove: ");
    scanf("%d",&id);
    flush();

    int idx = find_book(id);

    if(idx==-1){
        printf("Not found");
    } else {
        lib[idx].active = 0;
        printf("Removed");
    }

    sleep(1);
}

void showall(){
    system("cls");

    printf("ID | Title                     | Author\n");

    for(int i=0;i<30;i++){
        if(lib[i].active){
            printf("%d  | %-25s | %-20s\n",
                lib[i].bookid,
                lib[i].title,
                lib[i].author);
        }
    }

    getchar();
}

void show_id(){
    int id;

    system("cls");
    printf("Enter book id: ");
    scanf("%d",&id);
    flush();

    int idx = find_book(id);

    system("cls");

    if(idx==-1){
        printf("Not found");
    } else {
        printf("ID: %d\nTitle: %s\nAuthor: %s\n",
            lib[idx].bookid,
            lib[idx].title,
            lib[idx].author);
    }

    getchar();
}

int menu(){
    int c;

    while(1){
        system("cls");
        printf("LIBRARY SYSTEM\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Find Book\n");
        printf("4. Show All\n");
        printf("5. Exit\n");
        printf("Choice: ");

        if(scanf("%d",&c)!=1){
            flush();
            continue;
        }
        flush();
        return c;
    }
}

int main(){
    for(int i=0;i<30;i++)
        lib[i].active = 0;

    while(1){
        int c = menu();

        if(c==1) addbook();
        else if(c==2) removebook();
        else if(c==3) show_id();
        else if(c==4) showall();
        else if(c==5) break;
    }

    return 0;
}