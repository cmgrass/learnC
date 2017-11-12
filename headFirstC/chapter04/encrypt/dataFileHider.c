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

int close_file(FILE *myFile) {
    if (myFile) {
        fclose(myFile);
    }
}

int main(int argc, char *argv[])
{

    if ((argc < 2) || (argc >= 6)) {
        die_error_argError();
    }

    char optionChar = 0;
    char fileData[80] = {'\0'};
    FILE *fileToEncrypt = 0;
    FILE *fileToDecrypt = 0;
    FILE *encryptedFile = fopen("encryptedFile.txt", "w");
    FILE *decryptedFile = fopen("decryptedFile.txt", "w");

    while ((optionChar = getopt(argc, argv, "e:d:")) != EOF) {
        switch (optionChar) {
            case 'e':    /* Encrypt mode */
                fileToEncrypt = fopen(argv[optind - 1], "r");
                while(fgets(fileData, 80, fileToEncrypt) != NULL) {
                    encrypt(fileData);
                    fprintf(encryptedFile, "%s\n", fileData);
                }
                break;

            case 'd':    /* Decrypt mode */
                fileToDecrypt = fopen(argv[optind - 1], "r");
                while(fgets(fileData, 80, fileToDecrypt) != NULL) {
                    encrypt(fileData);
                    fprintf(decryptedFile, "%s\n", fileData);
                }
                break;

            default:
                die_error_argError();
        }
    }

    close_file(fileToEncrypt);
    close_file(fileToDecrypt);
    close_file(encryptedFile);
    close_file(decryptedFile);

    /*
      When getopt() is finisehd processing opions, `optind` returns the index
      of the next argument to be processed.
      We should update our argc and argv to account for this.
    */
    argc -= optind;
    argv += optind;

    return 0;
}
