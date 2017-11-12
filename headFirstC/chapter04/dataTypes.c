#include <stdio.h>
#include <limits.h>   /* This contains values for integer types */
#include <float.h>    /* THis contains values for float types */


int main()
{
    /* Sizes of integer types */
    printf("---Sizes Of---\nchar: %lu,\nshort: %lu,\nint: %lu,\nlong: %lu\n",
           sizeof(char), sizeof(short), sizeof(int), sizeof(long));

    /* Sizes of float types */
    printf("---Sizes Of---\nfloat: %lu,\ndouble: %lu,\nlong double: %lu,\n",
           sizeof(float), sizeof(double), sizeof(long double));

    /* Let's use some of the included libraries... */
    printf("The value of INT_MAX is: %i\n", INT_MAX);
    printf("The value of INT_MIN is: %i\n", INT_MIN);
    printf("An int takes up %lu bytes\n", sizeof(int));

    printf("The value of FLT_MAX is: %f\n", FLT_MAX);
    printf("The value of FLT_MIN is: %.50f\n", FLT_MIN);
    printf("A float takes up %lu bytes\n", sizeof(float));

    return 0;
}
