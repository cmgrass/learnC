#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void prompt(char *message)
{
    printf("%s\n> ", message);
}

int main()
{
    char card_name[3];
    prompt("Enter a card name:");
    scanf("%2s", card_name);    /* We use `2` characters b/c last char is nul*/

    int val = 0;
    char userChar = toupper(card_name[0]);

    /* Assign an integer value to the user's card */
    switch (userChar) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(&userChar);
    }

    printf("The value of your card is: %i\n", val);

    /* Check the range of the card so we know how to count it */
    if ((val >= 3) && (val <= 6)) {
        puts("Count has gone UP.");
    } else if (val == 10) {
        puts("Count has gone DOWN.");
    }

    return 0;
}
