#include <stdio.h>

int main(int argc, char *argv[]) {
    int x = 78;
    unsigned long y = 93;
    float z = 12.34;

    printf("Variables x = %d, y = %lu, z = %09.4f\nnote x = %#2.4x in hex\n", x, y, z, x);

    return 0;
}
