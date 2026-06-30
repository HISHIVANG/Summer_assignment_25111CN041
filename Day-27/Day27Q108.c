//Write a program to Create marksheet generation system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void flush();
int find_rollno(int rollno);
void show_name();
void show_rollno();
void show_all();
void id_stat(int id);
int create(int rollno, char name[], int m1, int m2, int m3);
void addstudent();
void removestudent();
int menu();

typedef struct student{
    char name[21];
    int rollno;
    int m1, m2, m3;
    int total;
    float percent;
    char grade;
    int active;
} stu;

stu list[30];

void flush(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int find_rollno(int rollno){
    for(int i = 0; i < 30; i++){
        if(list[i].active && list[i].rollno == rollno)
            return i;
    }
    return -1;
}

int calc_grade(float p){
    if(p >= 90) return 'A';
    else if(p >= 75) return 'B';
    else if(p >= 60) return 'C';
    else if(p >= 40) return 'D';
    else return 'F';
}

int create(int rollno, char name[], int m1, int m2, int m3){
    for(int i = 0; i < 30; i++){
        if(!list[i].active){
            list[i].rollno = rollno;
            strcpy(list[i].name, name);

            list[i].m1 = m1;
            list[i].m2 = m2;
            list[i].m3 = m3;

            list[i].total = m1 + m2 + m3;
            list[i].percent = list[i].total / 3.0;
            list[i].grade = calc_grade(list[i].percent);

            list[i].active = 1;
            return i;
        }
    }
    return -1;
}

void show_all(){
    system("cls");

    printf("Roll | Name                 | M1 | M2 | M3 | Total | %% | Grade\n");

    for(int i = 0; i < 30; i++){
        if(list[i].active){
            printf("%-4d | %-20s | %-2d | %-2d | %-2d | %-5d | %-5.2f | %c\n",
                list[i].rollno,
                list[i].name,
                list[i].m1,
                list[i].m2,
                list[i].m3,
                list[i].total,
                list[i].percent,
                list[i].grade
            );
        }
    }

    getchar();
}

void id_stat(int id){
    system("cls");

    if(id < 0 || id >= 30 || !list[id].active){
        printf("Not found");
        sleep(1);
        return;
    }

    printf("Roll | Name                 | M1 | M2 | M3 | Total | %% | Grade\n");

    printf("%-4d | %-20s | %-2d | %-2d | %-2d | %-5d | %-5.2f | %c\n",
        list[id].rollno,
        list[id].name,
        list[id].m1,
        list[id].m2,
        list[id].m3,
        list[id].total,
        list[id].percent,
        list[id].grade
    );

    getchar();
}

void show_rollno(){
    system("cls");

    int roll;
    printf("Enter roll no: ");
    scanf("%d", &roll);
    flush();

    id_stat(find_rollno(roll));
}

void show_name(){
    system("cls");

    char name[21];
    printf("Enter name: ");
    fgets(name, 21, stdin);
    name[strcspn(name, "\n")] = '\0';

    system("cls");

    printf("Roll | Name                 | M1 | M2 | M3 | Total | %% | Grade\n");

    for(int i = 0; i < 30; i++){
        if(list[i].active && strcmp(list[i].name, name) == 0){
            printf("%-4d | %-20s | %-2d | %-2d | %-2d | %-5d | %-5.2f | %c\n",
                list[i].rollno,
                list[i].name,
                list[i].m1,
                list[i].m2,
                list[i].m3,
                list[i].total,
                list[i].percent,
                list[i].grade
            );
        }
    }

    getchar();
}

void addstudent(){
    char name[21];
    int roll, m1, m2, m3;

    system("cls");

    printf("Enter name: ");
    fgets(name, 21, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter roll no: ");
    scanf("%d", &roll);

    if(find_rollno(roll) != -1){
        printf("Already exists");
        sleep(1);
        return;
    }

    printf("Enter marks M1 M2 M3: ");
    scanf("%d %d %d", &m1, &m2, &m3);

    create(roll, name, m1, m2, m3);

    printf("Done");
    sleep(1);

    flush();
}

void removestudent(){
    system("cls");

    int roll;
    printf("Enter roll no: ");
    scanf("%d", &roll);

    int id = find_rollno(roll);

    if(id == -1){
        printf("Not found");
    } else {
        list[id].active = 0;
        printf("Deleted");
    }

    sleep(1);
    flush();
}

int menu(){
    int c;

    while(1){
        system("cls");

        printf("MARKSHEET SYSTEM\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Find by Roll\n");
        printf("4. Find by Name\n");
        printf("5. Show All\n");
        printf("6. Exit\n");
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
        list[i].active = 0;

    while(1){
        int c = menu();

        if(c == 1) addstudent();
        else if(c == 2) removestudent();
        else if(c == 3) show_rollno();
        else if(c == 4) show_name();
        else if(c == 5) show_all();
        else if(c == 6) break;
    }

    return 0;
}