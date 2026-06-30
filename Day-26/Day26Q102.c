#include <stdio.h>
#include <string.h>

typedef struct personaldata {
    char name[21];
    unsigned int age;
    char gender;
    int isCitizen; 
} data;

int main() {
    data person;

    printf("Enter Full Name: ");
    fgets(person.name, sizeof(person.name), stdin);
    person.name[strcspn(person.name, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%u", &person.age);

    printf("Are you a citizen of this country? (1 = Yes, 0 = No): ");
    scanf("%d", &person.isCitizen);

    if (person.age >= 18 && person.isCitizen == 1) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote.\n");
    }

    printf("\n--- Voter Details ---\n");
    printf("Name: %s\n", person.name);
    printf("Age: %u\n", person.age);
    printf("Citizen: %s\n", person.isCitizen ? "Yes" : "No");

    return 0;
}