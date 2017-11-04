#include <stdio.h>

int main(int argc, int *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char myBytes[] = {0x25, 0x2, 0x33, 0x4F};
    char name[] = "Chr";
    char full_name[] = {
        'C', 'h', 'r', 'i','s',
        ' ', 'M', '.', ' ',
        'G', 'r', 'a', 's', 's', '\0'
    };

    printf("The size of an int is: %ld\n", sizeof(int));
    printf("The size of `areas` is: %ld\n", sizeof(areas));
    printf("The number if ints in `areas` is: %ld\n",
            sizeof(areas) / sizeof(int));
    printf("The first area is: %d, the second is: %d\n", areas[0], areas[1]);

    printf("The size of `myBytes` is: %ld\n", sizeof(myBytes));

    printf("The size of a char is: %ld\n", sizeof(char));
    printf("The size of `name` is: %ld\n", sizeof(name));
    printf("The number of chars in `name` is: %ld\n",
            sizeof(name) / sizeof(char));

    printf("The size of `full_name` is: %ld\n", sizeof(full_name));
    printf("The number of chars in `full_name` is: %ld\n",
            sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}
