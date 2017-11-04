#include <stdio.h>

/* This is a comment. */
int main(int argc, char *argv[])
{
    int distance = 100;

    // this is also a comment
    printf("You are %d miles away.\n", distance);
    printf("We should return %d.\n", 0);

    return 0;
}

/*
Commands:
$ make ex1  // `make` is a tool that knows how to build C programs.
cc -Wall -g ex1.c -o ex1
$./ex1  // `ex1` is now an executable file that can be run wiht `./ex1`
You are 100 miles away.
$
*/
