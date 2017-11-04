#include <stdio.h>
#include <assert.h>    /* Provides: `assert()` */
#include <stdlib.h>    /* Provides: `malloc()` */
#include <string.h>

/* Define a structure: `Person` */
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

/* Define a function which returns a pointer to an instance of struct: Person */
struct Person *Person_create(char *name, int age, int height, int weight)
{
    /* `malloc` allocates requested amount of memory. returns a pointer to it */
    struct Person *who = malloc(sizeof(struct Person));

    /* `assert` is a macro which prints diagnostic info if false
    We're doing to verify memory was allocated before we attempt to process it.
    */
    assert(who != NULL);

    /* `who` is a pointer to an instance of our structure.
    The `->` operator dereferences a member of a structure via a pointer.
    (It does offsetting of the address and length calculations for us)
    */
    /* `strdup()` duplicates a string. Because strings are pointers to a
    starting element, the return is a string, and therefore also a pointer.
    */
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    /* Return the pointer to a new instance of our person struct*/
    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    /* Deallocate previously allocated memory */
    /* We have to free `who->name` seperately because `strdup(name)` from an
    earlier function probably allocated the memory outside of what was allocated
    for the structure.
    */
    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    /* Make two people structures */
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    /* Print them out, and where they are in memory */
    printf("Joe is at memory location: %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location: %p:\n", frank);
    Person_print(frank);

    /* Make everyone age 20 years, then print them again */
    joe->age += 20;
    joe->height += 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    /* Destroy them both so we clean up */
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
