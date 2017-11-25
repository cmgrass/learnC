#include <stdarg.h>
#include <stdio.h>

void print_ints(int args, ...)
{
    va_list ap;
    va_start(ap, args);

    int i;

    for (i = 0; i < args; i++) {
       printf("argument: %i\n", va_arg(ap, int));
    }

    va_end(ap);
}

int main()
{
    print_ints(3, 2, 43, 2);
    print_ints(1, 235);
    print_ints(7, 2829, 10382, 28, 8, 353, 327, 12);

    return 0;
}
