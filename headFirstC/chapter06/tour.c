#include <stdio.h>


/* Build a recursive structure */
/*    NOTE: Recursive structures require `typedef struct <name>` syntax */
typedef struct island {
    char *name;
    char *open;
    char *close;
    struct island *next;
} island;

void print_island(island *curr_island)
{
   printf("Address of %s: %p, next island is at: %p\n",
          curr_island->name, curr_island, curr_island->next); 
}

void print_schedule_info(island *start)
{
    island *i = start;

    for (; i != NULL; i = i->next){
        printf("Island Name: %s, Open: %s-%s\n", i->name, i->open, i->close);
    }
}

island amity = {"Amity", "9:00", "17:00", NULL};
island craggy = {"Craggy", "9:00", "17:00", NULL};
island skull = {"Skull", "9:00", "17:00", NULL};
island isla_nubar = {"Isla Nubar", "9:00", "17:00", NULL};
island shutter = {"Shutter", "9:00", "17:00", NULL};

int main()
{
    amity.next = &craggy;
    craggy.next = &skull;
    skull.next = &isla_nubar; 
    isla_nubar.next = &shutter;

    print_island(&amity);
    print_island(&craggy);
    print_island(&skull); 
    print_island(&isla_nubar);
    print_island(&shutter);

    print_schedule_info(&amity);

    printf("Size of 'island' structure: %lu bytes.\n", sizeof(island));

    return 0;
}
