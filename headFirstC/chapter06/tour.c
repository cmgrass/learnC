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

    return 0;
}
