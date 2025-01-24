#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int FUCKING_INTEGER;

typedef struct human {
    char name[32];  // fields
    int age;
    struct human *father;
} Person;

void brithday(Person p) {
    p.age += 1;
}

void brithday2(Person *p) {
    // (*p).age += 1;
    p->age += 1;
}


Person *create_person(char name[32], int age) {
    Person *new_person = (Person *) calloc(1, sizeof(Person));
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->father = NULL;
    return new_person;
}

int main() {

    int x = 5;
    FUCKING_INTEGER y = 5;

    // Person 1
    struct human vc;
    strcpy(vc.name, "Vincent");
    vc.age = 18;

    Person anya;
    strcpy(anya.name, "Anya");
    anya.age = 3;

    printf("%s, %d\n", vc.name, vc.age);
    printf("%s, %d\n", anya.name, anya.age);

    brithday(vc);
    printf("%s, %d\n", vc.name, vc.age);

    brithday2(&vc);
    printf("%s, %d\n", vc.name, vc.age);

    // ------------------------
    Person *p1 = create_person("Vincent", 18);
    p1->father = create_person("Paco", 69);
    p1->father->father = &anya;


    printf("%s\n", p1->father->father->name);

}