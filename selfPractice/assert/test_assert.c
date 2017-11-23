#include <stdio.h>
#include <assert.h>

int main()
{
    int bacon = 2;
    int corn = (bacon * 2);

    printf("bacon: %i, corn: %i\n", bacon, corn);

    puts("check assert:");

    assert(bacon == corn);

    puts("PASSED");

    return 0;
}
