#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Function Prototypes */
void print_letters(int len, char arg[]);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++) {
        print_letters(strlen(argv[i]), argv[i]);
    }
}

void print_letters(int len, char arg[])
{
    int i = 0;

    for (i = 0; i < len; i++) {
        char ch = arg[i];

        if (isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d :", ch, ch);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
