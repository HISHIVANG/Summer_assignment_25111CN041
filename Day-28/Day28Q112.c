//Write a program to Create contact management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void flush();
int find_contact(char phone[]);
int create_contact(char name[], char phone[], char email[]);
int is_valid_phone(char phone[]);
int is_valid_email(char email[]);
void addcontact();
void removecontact();
void showall();
void showcontact();
int menu();

typedef struct contact{
    char name[21];
    char phone[15];
    char email[41];
    int active;
} con;

con clist[30];

void flush(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int is_valid_phone(char phone[]){
    if(strlen(phone) != 10) return 0;

    for(int i = 0; i < 10; i++){
        if(phone[i] < '0' || phone[i] > '9')
            return 0;
    }
    return 1;
}

int is_valid_email(char email[]){
    if(strlen(email) < 14) return 0;

    char end[] = "@fountain.com";
    int len = strlen(email);

    for(int i = len - 13, j = 0; i < len; i++, j++){
        if(email[i] != end[j])
            return 0;
    }
    return 1;
}

int find_contact(char phone[]){
    for(int i = 0; i < 30; i++){
        if(clist[i].active && strcmp(clist[i].phone, phone) == 0)
            return i;
    }
    return -1;
}

int create_contact(char name[], char phone[], char email[]){
    for(int i = 0; i < 30; i++){
        if(!clist[i].active){
            strcpy(clist[i].name, name);
            strcpy(clist[i].phone, phone);
            strcpy(clist[i].email, email);
            clist[i].active = 1;
            return i;
        }
    }
    return -1;
}

void addcontact(){
    char name[21], phone[15], email[41];

    system("cls");

    printf("Enter name: ");
    scanf("%20s", name);

    printf("Enter phone (10 digits): ");
    scanf("%14s", phone);

    if(!is_valid_phone(phone)){
        printf("Invalid phone");
        sleep(1);
        return;
    }

    if(find_contact(phone) != -1){
        printf("Contact already exists");
        sleep(1);
        return;
    }

    printf("Enter email (@fountain.com): ");
    scanf("%40s", email);

    if(!is_valid_email(email)){
        printf("Invalid email domain");
        sleep(1);
        return;
    }

    if(create_contact(name, phone, email) == -1){
        printf("Contact list full");
    } else {
        printf("Contact added");
    }

    sleep(1);
}

void removecontact(){
    char phone[15];

    system("cls");
    printf("Enter phone to delete: ");
    scanf("%14s", phone);

    int idx = find_contact(phone);

    if(idx == -1){
        printf("Not found");
    } else {
        clist[idx].active = 0;
        printf("Deleted");
    }

    sleep(1);
}

void showcontact(){
    char phone[15];

    system("cls");
    printf("Enter phone: ");
    scanf("%14s", phone);

    int idx = find_contact(phone);

    system("cls");

    if(idx == -1){
        printf("Not found");
    } else {
        printf("Name  : %s\nPhone : %s\nEmail : %s\n",
            clist[idx].name,
            clist[idx].phone,
            clist[idx].email);
    }

    getchar();
}

void showall(){
    system("cls");

    printf("Name        | Phone        | Email\n");

    for(int i = 0; i < 30; i++){
        if(clist[i].active){
            printf("%-10s | %-12s | %-20s\n",
                clist[i].name,
                clist[i].phone,
                clist[i].email);
        }
    }

    getchar();
}

int menu(){
    int c;

    while(1){
        system("cls");
        printf("CONTACT MANAGEMENT SYSTEM\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Find Contact\n");
        printf("4. Show All\n");
        printf("5. Exit\n");
        printf("Choice: ");

        if(scanf("%d", &c) != 1){
            flush();
            continue;
        }

        flush();
        return c;
    }
}

int main(){
    for(int i = 0; i < 30; i++)
        clist[i].active = 0;

    while(1){
        int c = menu();

        if(c == 1) addcontact();
        else if(c == 2) removecontact();
        else if(c == 3) showcontact();
        else if(c == 4) showall();
        else if(c == 5) break;
    }

    return 0;
}