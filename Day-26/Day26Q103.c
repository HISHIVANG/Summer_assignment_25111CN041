//Write a program to Create ATM simulation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct accountdetails{
    char account[41];
    char name[21];
    char password[21];
    int age;
    float balance;
} acc;

acc acclist[30];

void flush(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int is_valid_account(char account[]){
    if(strlen(account) < 14) return 0;

    char end[] = "@fountain.com";
    int read = strlen(account);

    for(int i = read - 13, j = 0; i < read; i++, j++){
        if(account[i] != end[j]) return 0;
    }
    return 1;
}

int find_account_id(char account[]){
    for(int id = 0; id < 30; id++){
        if(strcmp(account, acclist[id].account) == 0){
            return id;
        }
    }
    return -1;
}

int create_account(char account[], char name[], char password[], int age){
    for(int id = 0; id < 30; id++){
        if(acclist[id].account[0] == '\0'){
            strcpy(acclist[id].account, account);
            strcpy(acclist[id].name, name);
            strcpy(acclist[id].password, password);
            acclist[id].age = age;
            acclist[id].balance = 0;
            return id;
        }
    }
    return -1;
}

int menu(){
    int choice;
    while(1){
        system("cls");
        printf("_________________Menu____________________\n");
        printf("1. login\n2. sign up\n3. quit\n");
        printf("Command : ");

        if(scanf("%d", &choice) != 1){
            flush();
            continue;
        }
        flush();
        return choice;
    }
}

void sign_up(){
    char account[41] = "", name[21] = "", password[21] = "", repass[21] = "";
    int age = 0;
    int id;

    while(1){
        system("cls");
        printf("_________________Signup__________________\nenter /quit to exit\n");
        printf("Use email ending @fountain.com\n\n");
        if(!is_valid_account(account)){
            printf("Enter account name: ");
            scanf("%s", account);
            if(strcmp(account, "/quit") == 0) return;
            continue;
        }

        id = find_account_id(account);
        if(id != -1){
            printf("Account already exists");
            account[0] = '\0';
            sleep(2);
            continue;
        }

        if(password[0] == '\0'){
            printf("Create password: ");
            scanf("%s", password);
            if(strcmp(password, "/quit") == 0) return;

            if(strlen(password) < 8){
                printf("Too short");
                password[0] = '\0';
                sleep(2);
            }
            continue;
        }

        if(repass[0] == '\0'){
            printf("Re-enter password: ");
            scanf("%s", repass);

            if(strcmp(repass, password) != 0){
                printf("Try again");
                repass[0] = '\0';
                password[0] = '\0';
                sleep(2);
            }
            continue;
        }

        if(name[0] == '\0'){
            printf("Enter name: ");
            scanf("%s", name);
            continue;
        }

        if(age == 0){
            printf("Enter age: ");
            scanf("%d", &age);

            if(age < 16){
                printf("Too young");
                sleep(2);
                return;
            }
            continue;
        }

        if(create_account(account, name, password, age) == -1){
            printf("System full");
        } else {
            printf("Account created");
        }

        sleep(2);
        return;
    }
}

void login(){
    char account[41] = "", password[21] = "";
    int id = -1;
    int choice;

    while(1){
        system("cls");
        printf("_________________login___________________\n");

        if(!is_valid_account(account)){
            printf("Enter account: ");
            scanf("%s", account);
            if(strcmp(account, "/quit") == 0) return;
        }

        id = find_account_id(account);
        if(id == -1){
            printf("Account not found");
            account[0] = '\0';
            sleep(2);
            continue;
        }

        if(password[0] == '\0'){
            printf("Enter password: ");
            scanf("%s", password);

            if(strcmp(password, acclist[id].password) != 0){
                printf("Wrong password");
                password[0] = '\0';
                sleep(2);
                continue;
            }
        }

        while(1){
            system("cls");
            printf("Welcome %s\n", acclist[id].name);
            printf("1. Withdraw\n2. Deposit\n3. Balance\n4. Logout\n");
            printf("Choice: ");

            if(scanf("%d", &choice) != 1){
                flush();
                continue;
            }

            float money;

            if(choice == 1){
                printf("Withdraw: ");
                scanf("%f", &money);

                if(money > acclist[id].balance || money < 0){
                    printf("Invalid");
                } else {
                    acclist[id].balance -= money;
                    printf("Done");
                }
                sleep(2);
            }

            else if(choice == 2){
                printf("Deposit: ");
                scanf("%f", &money);

                if(money < 0){
                    printf("Invalid");
                } else {
                    acclist[id].balance += money;
                    printf("Done");
                }
                sleep(2);
            }

            else if(choice == 3){
                printf("Balance: %.2f", acclist[id].balance);
                sleep(3);
            }

            else if(choice == 4){
                break;
            }
        }

        return;
    }
}

void ATM(){
    while(1){
        int choice = menu();

        if(choice == 1) login();
        else if(choice == 2) sign_up();
        else if(choice == 3) break;
    }
}

int main(){
    for(int i = 0; i < 30; i++)
        acclist[i].account[0] = '\0';

    ATM();
    return 0;
}