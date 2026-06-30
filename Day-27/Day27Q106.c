// Write a program to Create employee management system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void flush();
int find_empid(int empid);
void show_name();
void show_empid();
void show_department();
void id_stat(int id);
int create(int empid, char name[], char department[]);
void addemployee();
void removeemployee();
void showall();
int menu();
int find_employees();

typedef struct employee{
    char name[21];
    int empid;
    char department[21];
    int active;
} emp;

emp emplist[30];

void flush(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int find_empid(int empid){
    for(int id = 0; id < 30; id++){
        if(empid == emplist[id].empid && emplist[id].active){
            return id;
        }
    }
    return -1;
}

void show_name(){
    system("cls");
    char name[21];

    printf("Enter name: ");
    fgets(name, 21, stdin);
    name[strcspn(name, "\n")] = '\0';

    if(strcmp(name, "/quit") == 0) return;

    system("cls");
    printf("S.no. | Name                 | Emp ID              | Department");

    int i = 1;

    for(int id = 0; id < 30; id++){
        if((strcmp(name, emplist[id].name) == 0) && emplist[id].active){
            printf("\n%-4d. | %-20s | %-20d | %-20s",
                   i++, emplist[id].name, emplist[id].empid, emplist[id].department);
        }
    }

    flush();
    getchar();
}

void show_empid(){
    system("cls");
    int empid = -1;

    printf("Enter empid: ");
    scanf("%d", &empid);

    if(empid < 0) return;

    system("cls");
    id_stat(find_empid(empid));

    flush();
    getchar();
}

void removeemployee(){
    system("cls");
    int empid = -1;

    printf("Enter empid to delete: ");
    scanf("%d", &empid);

    if(empid < 0) return;

    system("cls");

    int id = find_empid(empid);

    if(id < 0){
        printf("Not found");
        sleep(1);
        return;
    }

    emplist[id].active = 0;
    printf("Done");
    sleep(2);
}

void show_department(){
    system("cls");
    char department[21];

    printf("Enter department: ");
    fgets(department, 21, stdin);
    department[strcspn(department, "\n")] = '\0';

    if(strcmp(department, "/quit") == 0) return;

    system("cls");
    printf("S.no. | Name                 | Emp ID              | Department");

    int i = 1;

    for(int id = 0; id < 30; id++){
        if((strcmp(department, emplist[id].department) == 0) && emplist[id].active){
            printf("\n%-4d. | %-20s | %-20d | %-20s",
                   i++, emplist[id].name, emplist[id].empid, emplist[id].department);
        }
    }

    flush();
    getchar();
}

void id_stat(int id){
    system("cls");

    if(id < 0 || id > 29){
        printf("Not found");
        sleep(1);
        return;
    }

    printf("S.no. | Name                 | Emp ID              | Department");

    if(emplist[id].active){
        printf("\n%-4d. | %-20s | %-20d | %-20s",
               1, emplist[id].name, emplist[id].empid, emplist[id].department);

        flush();
        getchar();
    }
    else{
        printf("Not found");
        sleep(1);
    }
}

int create(int empid, char name[], char department[]){
    for(int id = 0; id < 30; id++){
        if(emplist[id].active == 0){
            emplist[id].empid = empid;
            strcpy(emplist[id].name, name);
            strcpy(emplist[id].department, department);
            emplist[id].active = 1;
            return id;
        }
    }
    return -1;
}

void addemployee(){
    char name[21]; name[0] = '\0';
    char department[21]; department[0] = '\0';
    int empid = -1;
    int id = -1;

    while(1){
        system("cls");
        printf("_________________add_____________________\n");

        if(name[0] == '\0'){
            printf("Enter name: ");
            fgets(name, 21, stdin);
            name[strcspn(name, "\n")] = '\0';

            if(strcmp(name, "/quit") == 0) break;

            if(strlen(name) < 2){
                printf("Try Again");
                name[0] = '\0';
                sleep(2);
            }
            continue;
        }

        printf("Name : %s\n", name);

        if(empid < 0){
            printf("Enter empid: ");
            if(scanf(" %d", &empid) != 1){
                flush();
                continue;
            }
            if(empid < 0) break;
            continue;
        }

        id = find_empid(empid);

        if(id != -1){
            printf("Already registered.");
            empid = -1;
            sleep(2);
            break;
        }

        printf("EmpID : %d\n", empid);

        if(department[0] == '\0'){
            printf("Enter department: ");
            scanf(" %20s", department);

            if(strcmp(department, "/quit") == 0) break;

            if(strlen(department) < 1){
                printf("Try Again");
                department[0] = '\0';
                sleep(2);
            }
            continue;
        }

        printf("Department : %s\n", department);

        if((id = create(empid, name, department)) == -1){
            printf("Site is closed\nPlease contact admin.");
            sleep(2);
            break;
        }

        printf("Done");
        sleep(1);
        break;
    }
}

void showall(){
    system("cls");

    printf("S.no. | Name                 | Emp ID              | Department");

    int i = 1;

    for(int id = 0; id < 30; id++){
        if(emplist[id].active){
            printf("\n%-4d. | %-20s | %-20d | %-20s",
                   i++, emplist[id].name, emplist[id].empid, emplist[id].department);
        }
    }

    flush();
    getchar();
}

int menu(){
    int choice;

    while(1){
        system("cls");
        printf("_________________Menu____________________\n");
        printf("1. Add employee\n2. Remove employee\n3. Find employee\n4. Show all employees\n5. Exit\n");
        printf("Command : ");

        if(scanf(" %d", &choice) != 1){
            flush();
            continue;
        }

        flush();
        return choice;
    }
}

int find_employees(){
    int choice;

    while(1){
        system("cls");
        printf("_______________find_employee________________\n");
        printf("Find employees by :\n1. name\n2. empid\n3. department\n");
        printf("\nCommand : ");

        if(scanf(" %d", &choice) != 1){
            flush();
            continue;
        }

        flush();
        return choice;
    }
}

int main(){
    for(int i = 0; i < 30; i++){
        emplist[i].active = 0;
    }

    while(1){
        int choice = menu();

        if(choice == 1) addemployee();
        else if(choice == 2) removeemployee();
        else if(choice == 3){
            choice = find_employees();
            if(choice == 1) show_name();
            else if(choice == 2) show_empid();
            else if(choice == 3) show_department();
        }
        else if(choice == 4) showall();
        else if(choice == 5) break;
    }

    return 0;
}