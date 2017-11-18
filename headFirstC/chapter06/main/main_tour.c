#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct island {
    char *name;
    char *open;
    char *close;
    struct island *next;
} island;

island *create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->open = "9:00";
    i->close = "17:00";
    i->next = NULL;

    return i;
}

void display(island *start)
{
    island *i = start;
    for (; i != NULL; i = i->next) { 
        printf("Island Name: %s, Open: %s-%s\n", i->name, i->open, i->close);
    }
}

void release(island *start)
{
    island *i = start;
    island *next = NULL;

    for (; i != NULL; i = next) {
        next = i->next;
        free(i->name);
        free(i);
    }
}

int main()
{
    char name[80] = {'\0'};
    island *start = NULL;
    island *next = NULL;
    island *i = NULL;
 
    for (; fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start == NULL) {
            start = next; 
        }
        if (i != NULL) {
            i->next = next;
        } 
    } 
    
    display(start);
    release(start);
    
    return 0;
}
