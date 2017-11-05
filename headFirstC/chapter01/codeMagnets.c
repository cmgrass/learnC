#include <stdio.h>
#include <stdlib.h>

int main()
{
    char card_name[3];
    puts("Enter a card name: ");
    scanf("%2s", card_name);    /* We use `2` characters b/c last char is nul*/

    int val = 0;

    if ((card_name[0] == 'K') || (card_name[0] == 'k')) {
        val = 10;
    } else if ((card_name[0] == 'Q') || (card_name[0] == 'q')) {
        val = 10;
    } else if ((card_name[0] == 'J') || (card_name[0] == 'j')) {
        val = 10;
    } else if ((card_name[0] == 'A') || (card_name[0] == 'a')) {
        val = 11;
    } else {
        val = atoi(card_name);
    }

    printf("This is the value of your card: %i\n", val);

    return 0;
}
