#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Setup the two arrays we care about */
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank", "Mary",
        "John", "Lisa"
    };

    /* Safely get the size of `ages` */
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    /* First way using indexing */
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    /* Setup pointers to the start of the arrays */
    int *curr_age = ages;    /* Same as: `= &ages[0]*/
    char **curr_name = names;    /* Need the `**` becuase point to string */

    /* Second way using pointers */
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", *(curr_name + i), *(curr_age + i));    /* the value at `base address + i`*/
    }

    printf("---\n");

    /* Third way, pointers are just arrays */
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", curr_name[i], curr_age[i]);   /* `ith` value at that address */
    }

    printf("---\n");

    /* Fourth way, stupid complex way */
    /*
    This works because:
        An array (like `names`) is just the base address for a sequence of bytes
        in memory.
        So we initialize our pointer variables to be the array base addresses.
        Each time we loop through, we increment the pointer variable value,
        adding `1` to the array base address each time.
        The loop runs until the difference between current address and base
        address equals the length of the array.
        Printing the value works by the `*` operator,
        saying: "the value at the current address".
    */
    for (curr_name = names, curr_age = ages;
            (curr_age - ages) < count; curr_name++, curr_age++) {
        printf("%s has %d years alive.\n", *curr_name, *curr_age);
    }

    return 0;
}
