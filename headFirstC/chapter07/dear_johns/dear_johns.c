#include <stdio.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE, FRIENDZONE};
typedef struct {
    char *name;
    enum response_type type;
} response;

void greeting(response r)
{
    printf("Dear %s,\n", r.name);
}

void dump(response r)
{
    puts("You've been dumped");
}

void second_chance(response r)
{
    puts("Congrats, there's a second chance.");
}

void marriage(response r)
{
    puts("You have a marriage proposal.");
}

void friendzone(response r)
{
    puts("Uh oh... You've been friendzoned...");
}

int main()
{
    response r[] = {
        {"Mike", DUMP}, {"Judy", DUMP},
        {"Kyle", SECOND_CHANCE}, {"Alberto", MARRIAGE},
        {"Janice", FRIENDZONE}
    };

    /* Make an array of function pointers */
    void (*responses[]) (response) = {dump, second_chance, marriage, friendzone};

    int i;

    /* loop through each of our response structures, call the matching function */ 
    for (i = 0; i < 5; i++) {
        responses[(r[i].type)](r[i]);
    } 

    return 0;
}
