//Write a program to Create salary management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void flush();
int find_empid(int empid);
void show_name();
void show_empid();
void show_department();
void show_salary();
void id_stat(int id);
int create(int empid, char name[], char department[], float salary);
void addemployee();
void removeemployee();
void showall();
int menu();
int find_employees();

typedef struct employee{
    char name[21];
    int empid;
    char department[21];
    float salary;
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

void show_salary(){
    system("cls");

    float salary;
    printf("Enter salary: ");
    scanf("%f", &salary);
    flush();

    system("cls");
    printf("S.no. | Name                 | Emp ID              | Department          | Salary");

    int i = 1;

    for(int id = 0; id < 30; id++){
        if(emplist[id].active && emplist[id].salary == salary){
            printf("\n%-4d. | %-20s | %-20d | %-20s | %.2f",
                   i++,
                   emplist[id].name,
                   emplist[id].empid,
                   emplist[id].department,
                   emplist[id].salary);
        }
    }

    flush();
    getchar();
}

void show_name(){
    system("cls");

    char name[21];
    printf("Enter name: ");
    fgets(name, 21, stdin);
    name[strcspn(name, "\n")] = '\0';

    system("cls");

    printf("S.no. | Name                 | Emp ID              | Department          | Salary");

    int i = 1;

    for(int id = 0; id < 30; id++){
        if((strcmp(name, emplist[id].name) == 0) && emplist[id].active){
            printf("\n%-4d. | %-20s | %-20d | %-20s | %.2f",
                   i++,
                   emplist[id].name,
                   emplist[id].empid,
                   emplist[id].department,
                   emplist[id].salary);
        }
    }

    flush();
    getchar();
}

void show_empid(){
    system("cls");

    int empid;
    printf("Enter empid: ");
    scanf("%d", &empid);
    flush();

    id_stat(find_empid(empid));
    getchar();
}

void show_department(){
    system("cls");

    char department[21];
    printf("Enter department: ");
    fgets(department, 21, stdin);
    department[strcspn(department, "\n")] = '\0';

    system("cls");

    printf("S.no. | Name                 | Emp ID              | Department          | Salary");

    int i = 1;

    for(int id = 0; id < 30; id++){
        if((strcmp(department, emplist[id].department) == 0) && emplist[id].active){
            printf("\n%-4d. | %-20s | %-20d | %-20s | %.2f",
                   i++,
                   emplist[id].name,
                   emplist[id].empid,
                   emplist[id].department,
                   emplist[id].salary);
        }
    }

    flush();
    getchar();
}

void id_stat(int id){
    system("cls");

    if(id < 0 || id > 29 || !emplist[id].active){
        printf("Not found");
        sleep(1);
        return;
    }

    printf("S.no. | Name                 | Emp ID              | Department          | Salary");

    printf("\n%-4d. | %-20s | %-20d | %-20s | %.2f",
           1,
           emplist[id].name,
           emplist[id].empid,
           emplist[id].department,
           emplist[id].salary);
}

int create(int empid, char name[], char department[], float salary){
    for(int id = 0; id < 30; id++){
        if(emplist[id].active == 0){
            emplist[id].empid = empid;
            strcpy(emplist[id].name, name);
            strcpy(emplist[id].department, department);
            emplist[id].salary = salary;
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
    float salary = -1;
    int id;

    while(1){
        system("cls");

        if(name[0] == '\0'){
            printf("Enter name: ");
            fgets(name, 21, stdin);
            name[strcspn(name, "\n")] = '\0';
            continue;
        }

        if(empid < 0){
            printf("Enter empid: ");
            scanf("%d", &empid);
            flush();
            continue;
        }

        if(department[0] == '\0'){
            printf("Enter department: ");
            scanf("%20s", department);
            continue;
        }

        if(salary < 0){
            printf("Enter salary: ");
            scanf("%f", &salary);
            flush();
            continue;
        }

        id = create(empid, name, department, salary);

        if(id == -1){
            printf("Database Full");
        } else {
            printf("Done");
        }

        sleep(1);
        break;
    }
}

void removeemployee(){
    system("cls");

    int empid;
    printf("Enter empid: ");
    scanf("%d", &empid);
    flush();

    int id = find_empid(empid);

    if(id == -1){
        printf("Not found");
    } else {
        emplist[id].active = 0;
        printf("Done");
    }

    sleep(1);
}

void showall(){
    system("cls");

    printf("S.no. | Name                 | Emp ID              | Department          | Salary");

    int i = 1;

    for(int id = 0; id < 30; id++){
        if(emplist[id].active){
            printf("\n%-4d. | %-20s | %-20d | %-20s | %.2f",
                   i++,
                   emplist[id].name,
                   emplist[id].empid,
                   emplist[id].department,
                   emplist[id].salary);
        }
    }

    getchar();
}

int menu(){
    int choice;

    while(1){
        system("cls");
        printf("1. Add\n2. Remove\n3. Find\n4. Show all\n5. Exit\n");
        printf("Choice: ");

        if(scanf("%d", &choice) != 1){
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
        printf("Find by:\n");
        printf("1. Name\n2. EmpID\n3. Department\n4. Salary\n"); // UPDATED
        printf("Choice: ");

        scanf("%d", &choice);
        flush();

        return choice;
    }
}

int main(){
    for(int i = 0; i < 30; i++)
        emplist[i].active = 0;

    while(1){
        int choice = menu();

        if(choice == 1) addemployee();
        else if(choice == 2) removeemployee();
        else if(choice == 3){
            choice = find_employees();

            if(choice == 1) show_name();
            else if(choice == 2) show_empid();
            else if(choice == 3) show_department();
            else if(choice == 4) show_salary();   // FIXED HERE
        }
        else if(choice == 4) showall();
        else if(choice == 5) break;
    }

    return 0;
}