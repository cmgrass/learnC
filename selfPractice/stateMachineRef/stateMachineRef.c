/*
This example comes from:
Introduction to Embedded Systems,
Using ANSI C and the Arduino Development Environment,
David Russel
Section 2.11 - Example 2.74
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Declare a pointer to a function with no return and an integer argument. */
/* We use `typedef` as best practice so it becomes easier to pass function
pointer into other functions */
typedef void (*PointerToStateFunction) (int val);

/* Make a new data type for our states */
/*
Enumeration works by assigning a constant keyword to a value of zero.
For each "enumeration", it increments the value by one for each successive
element in the list. in this case,
`STATE_ONE` represents integer 0
`STATE_TWO` represents integer 1
*/
typedef enum {
    STATE_ONE,
    STATE_TWO
} States;

typedef struct {
    // <TYPE> <MEMBER>
    States theState;
    PointerToStateFunction theStateFunction;
} StateEntry;

void StateOne(int val)
{
    printf("You are in state 1. The value received was: %d\n", val);
}

void StateTwo(int val)
{
    printf("You are in state 2. The value received was: %d\n", val);
}

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

static States m_state = STATE_ONE;
const static StateEntry m_stateTable[] =
{
    // <Member: `theState`>, <Member: `theStateFunction`>
    {STATE_ONE, StateOne},
    {STATE_TWO, StateTwo},
};

int main(int argc, char *argv[])
{
    if (argc < 3) die("USAGE: <`1` or `2`> <int>");

    char userStateVal = atoi(argv[1]);
    int userParamVal = atoi(argv[2]);

    printf("Argument Integers: %d, %d\n", userStateVal, userParamVal);

    switch (userStateVal) {

        case 1:
            m_state = STATE_ONE;
            break;

        case 2:
            m_state = STATE_TWO;
            break;

        default:
            die("USAGE: <'1' or '2'> <int>");
            break;
    }

    /*
    Remember that `m_state` is of an enumerated type. Therefore the value
    we index by is UNRELATED to the member element of the same type within
    the structure.
    `m_stateTable[<index>]` is unrelated to m_stateTable[i].theState.
    */
    m_stateTable[m_state].theStateFunction(userParamVal);
    printf("m_stateTable.theState == %d (enumerated value) \n",
           m_stateTable[m_state].theState);

    return 0;
}
