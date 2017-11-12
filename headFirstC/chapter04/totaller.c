#include <stdio.h>
#include "totaller.h"    /* The quotes tell compiler to look for local file. */

/*
  NOTE:
    Local header files can be stored in subdirectories, but usually they are
    stored in the same path as the .c file.
*/

float total = 0.0;
short count = 0;
short tax_percent = 6;

int main()
{
    float val = 0.0;
    puts("price of item: ");
    while (scanf("%f", &val) == 1) {
        printf("Total so far: %.2f\n", add_with_tax(val));
        puts("Price of item: ");
    }
    printf("\nFinal Total: %.2f\n", total);
    printf("\nNumber of Items: %hi\n", count);    /* %hi is used for shorts */

    return 0;
}

float add_with_tax(float f) {
    float tax_rate = 1 + (tax_percent / 100.0);
    total += (f * tax_rate);
    count += 1;
    return total;
}
