#include <stdio.h>
#include "encrypt.h"

int main()
{
    char msg[80] = {'\0'};
    while (fgets(msg, 80, stdin) != NULL) {
        if (msg[0] == '\n') {
            break;
        }
        encrypt(msg);
        printf("%s", msg);
    }
    return 0;
}
