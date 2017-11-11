#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    puts("----- PRINTING ARGS -----");
    printf("argc: %d\n", argc);

    int i = 0;

    for (i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    puts("-------------------------\n\n");


    /* ./categorize mermaid mermaid.csv Elvis elvises.csv the_rest.csv */
    if (argc != 6) {
        puts("ERROR: Must give 5 arguments");
        return 1;
    }

    char line[80] = {0};
    FILE *in = fopen("gpsdata.csv", "r");
    FILE *file1 = fopen(argv[2], "w");
    FILE *file2 = fopen(argv[4], "w");
    FILE *file3 = fopen(argv[5], "w");

    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, argv[1])) {
            fprintf(file1, "%.80s\n", line);
        } else if (strstr(line, argv[3])) {
            fprintf(file2, "%.80s\n", line);
        } else {
            fprintf(file3, "%.80s\n", line);
        }
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}
