//Write a program to Create ticket booking system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void flush();

int find_ticket(int id);
int create_ticket(int id, char name[], char movie[], int seats);

void bookticket();
void cancelticket();
void showticket();
void showall();
int menu();

typedef struct ticket{
    int ticketid;
    char name[21];
    char movie[21];
    int seats;
    int active;
} tic;

tic tlist[30];

void flush(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int find_ticket(int id){
    for(int i = 0; i < 30; i++){
        if(tlist[i].active && tlist[i].ticketid == id)
            return i;
    }
    return -1;
}

int create_ticket(int id, char name[], char movie[], int seats){
    for(int i = 0; i < 30; i++){
        if(!tlist[i].active){
            tlist[i].ticketid = id;
            strcpy(tlist[i].name, name);
            strcpy(tlist[i].movie, movie);
            tlist[i].seats = seats;
            tlist[i].active = 1;
            return i;
        }
    }
    return -1;
}

void bookticket(){
    char name[21], movie[21];
    int id, seats;

    system("cls");

    printf("Enter ticket id: ");
    scanf("%d", &id);
    flush();

    if(find_ticket(id) != -1){
        printf("Ticket already exists");
        sleep(1);
        return;
    }

    printf("Enter name: ");
    scanf("%20s", name);

    printf("Enter movie: ");
    scanf("%20s", movie);

    printf("Enter seats: ");
    scanf("%d", &seats);
    flush();

    if(seats <= 0){
        printf("Invalid seats");
        sleep(1);
        return;
    }

    if(create_ticket(id, name, movie, seats) == -1){
        printf("Booking full");
    } else {
        printf("Ticket booked");
    }

    sleep(1);
}

void cancelticket(){
    int id;

    system("cls");
    printf("Enter ticket id: ");
    scanf("%d", &id);
    flush();

    int idx = find_ticket(id);

    if(idx == -1){
        printf("Not found");
    } else {
        tlist[idx].active = 0;
        printf("Cancelled");
    }

    sleep(1);
}

void showticket(){
    int id;

    system("cls");
    printf("Enter ticket id: ");
    scanf("%d", &id);
    flush();

    int idx = find_ticket(id);

    system("cls");

    if(idx == -1){
        printf("Not found");
    } else {
        printf("Ticket ID: %d\nName: %s\nMovie: %s\nSeats: %d\n",
            tlist[idx].ticketid,
            tlist[idx].name,
            tlist[idx].movie,
            tlist[idx].seats);
    }

    getchar();
}

void showall(){
    system("cls");

    printf("ID | Name        | Movie       | Seats\n");

    for(int i = 0; i < 30; i++){
        if(tlist[i].active){
            printf("%d  | %-10s | %-10s | %d\n",
                tlist[i].ticketid,
                tlist[i].name,
                tlist[i].movie,
                tlist[i].seats);
        }
    }

    getchar();
}

int menu(){
    int c;

    while(1){
        system("cls");
        printf("TICKET BOOKING SYSTEM\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Find Ticket\n");
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
        tlist[i].active = 0;

    while(1){
        int c = menu();

        if(c == 1) bookticket();
        else if(c == 2) cancelticket();
        else if(c == 3) showticket();
        else if(c == 4) showall();
        else if(c == 5) break;
    }

    return 0;
}