#include <stdio.h>

/* Function Prototype */
char returnLowercase(char letter);
void printVowel(int i, char letter);
void noVowel(int i, char letter);

int main(int argc, char *argv[])
{
    /* Check if we should abort */
    if (argc != 2) {
        printf("You must enter ONE argument.\n");
        return 1;
    }

    printf("We will dissect your argument's letters to find vowels\n");

    int i = 0;

    /* Go through each character of the given argument until null terminator */
    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = returnLowercase(argv[1][i]);

        switch (letter) {
            case 'a':
                printVowel(i, 'A');
                break;

            case 'e':
                printVowel(i, 'E');
                break;

            case 'i':
                printVowel(i, 'I');
                break;

            case 'o':
                printVowel(i, 'O');
                break;

            case 'u':
                printVowel(i, 'U');
                break;

            case 'y':
                /* `Y` is only sometimes a vowel */
                if (i > 2) {
                    printVowel(i, 'Y');
                } else {
                    noVowel(i, letter);
                }
                break;

            default:
                noVowel(i, letter);
        }
    }

    return 0;
}

char returnLowercase(char letter)
{
    if (letter >= 65 && letter <= 89) {
        return letter + 32;
    } else {
        return letter;
    }
}

void printVowel(int i, char letter)
{
    printf("%d: '%c' (VOWEL)\n", i, letter);
}

void noVowel(int i, char letter)
{
    printf("%d: '%c' is NOT a vowel.\n", i, letter);
}
