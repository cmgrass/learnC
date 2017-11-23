#include <stdio.h>
#include <string.h>
#include <ctype.h>

void string_to_upper(char (*string_p) [80], int size)
{
    int i = 0;
    int k;
    int new_char = 0;
    for (i = 0; i < size; i++) {
        k = 0;
        printf("START: %i\n", i);
        while (string_p[i][k]) {
            new_char = toupper(string_p[i][k]);
            string_p[i][k] = new_char;
            printf("%c", (char)new_char);
            k++;
        }
        puts("");
        printf("%s\n", string_p[i]);
        puts("DONE\n");
    }
}

/* find sports fans who don't like bieber */
void find(char (*string_p) [80], int size)
{
    string_to_upper(string_p, size);

    int i;
    puts("Search results:");
    puts("-------------------------");

    for (i = 0; i < size; i++) {
        if (strstr(string_p[i], "SPORTS") && !strstr(string_p[i], "BIEBER")) {
            printf("%s\n", string_p[i]);
        }
    }
    puts("-------------------------");
}

int main()
{

    int NUM_ADS = 7;
    char ADS[7][80];
    strcpy(ADS[0], "William: SBM GSOH likes sports, TV, dining");
    strcpy(ADS[1], "Matt: SWM NS likes art, movies, theatre");
    strcpy(ADS[2], "Luis: SLM ND likes books, theatre, and art");
    strcpy(ADS[3], "Mike: DWM DS likes trucks, sports and Bieber");
    strcpy(ADS[4], "Peter: SAM likes chess, working out and art");
    strcpy(ADS[5], "Josh: SJM likes sports, movies and theatre");
    strcpy(ADS[6], "Jed: DBM likes theatre, books and dining");    

    find(ADS, NUM_ADS);

    return 0;
}
