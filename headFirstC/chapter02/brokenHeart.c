#include <stdio.h>

void print_offset(char *msg)
{
    puts(msg + 6);

    /*
    EXPLANATION:
    ~ This works because if we did `*(msg + 6)`, that means print the
    ~ 7th character. What we want is to print the string STARTING AT AN ADDRESS.
    ~ That starting address is the address of the string plus 6.
    */
}

int main()
{
    char *msg_from_amy = "Don't call me.";
    print_offset(msg_from_amy);
    return 0;
}
