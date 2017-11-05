#include <stdio.h>

int main(int argc, char *argv[])
{
    char name[20];
    puts("Enter your name: ");
    scanf("%19s", name);
    printf("You entered the following name: %s\n", name);
    name[12] = '\0'; /* Manually set terminator character */
    printf("I hacked it to be this: %s\n", name);
}
