#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "encrypt.h"


int die_error_argError() {
    puts("ERROR: Argument error.");
    puts("Expecing one or two arguments:");
    puts("./dataFileHider -d <file_to_decrypt> -e <file_to_encrypt>");

    exit(1);
}

int main(int argc, char *argv[])
{

    if ((argc < 2) || (argc >= 6)) {
        die_error_argError();
    }

    char optionChar = 0;

    while ((optionChar = getopt(argc, argv, "e:d:")) != EOF) {
        switch (optionChar) {
            case 'e':    /* Encrypt mode */
                encrypt(argv[optind - 1]);
                printf("%s\n", argv[optind - 1]);
                break;
            case 'd':    /* Decrypt mode */
                encrypt(argv[optind - 1]);
                printf("%s\n", argv[optind - 1]);
                break;
            default:
                die_error_argError();
        }
    }

    /*
      When getopt() is finisehd processing opions, `optind` returns the index
      of the next argument to be processed.
      We should update our argc and argv to account for this.
    */
    argc -= optind;
    argv += optind;

    return 0;
}
