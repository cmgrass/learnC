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
    int card_count = 0;
    char game_active = 1;

    puts("Welcome to \"The Card Game\", enter `x` to exit.\n");

    while (game_active) {
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
            case 'X':
                val = -1;
                game_active = 0;
                break;
            default:
                val = atoi(card_name);
                if ((val < 2) || (val > 10)) {
                    val = -1;
                    puts("Error, enter a valid value");
                    continue;
                }
        }

        if (!game_active) {
            puts("Game has ended.");
            break;
        }

        printf("The value of your card is: %i\n", val);

        /* Check the range of the card so we know how to count it */
        if ((val >= 3) && (val <= 6)) {
            card_count++;
            puts("Count has gone UP.");
        } else if (val == 10) {
            card_count--;
            puts("Count has gone DOWN.");
        }

        printf("Current count: %i.\n", card_count);
        puts("");
    }

    return 0;
}
