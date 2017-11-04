#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 25;
    while (i > 0) {
        printf("%d\n", i);
        unsigned char k = 0;
        while (k < 8) {
            printf("  ~%d\n", k);
            k++;
        }
        i--;
    }

    return 0;
}
