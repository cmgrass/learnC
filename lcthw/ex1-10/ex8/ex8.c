#include <stdio.h>
/* Function Prototype */
void printArgs(int *argcPtr, char **argvPtr);

int main(int argc, char *argv[])
{
    //int i = 0;

    if (argc == 1) {
        printf("You haven't entered any user arguments. You suck.\n");
    } else if (argc > 1 && argc < 4) {
        printArgs(&argc, argv);
    } else if (argc == 4) {
        printf("Don't enter any more arguments than this!\n");
        printArgs(&argc, argv);
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}

void printArgs(int *argcPtr, char **argvPtr)
{
    int i = 0;

    printf("Here's the function arguments:\n");

    for (i = 0; i < *argcPtr; i++) {
        printf("%s : ", argvPtr[i]);
        /* we could also do this: */
        printf("%s ", *(argvPtr + i));

        printf("\n");
    }
}
