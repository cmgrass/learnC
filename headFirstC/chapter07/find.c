#include <stdio.h>
#include <string.h>
#include <ctype.h>

int match_sports_no_bieber(char *string_p)
{
    return (strstr(string_p, "SPORTS") && !strstr(string_p, "BIEBER"));
}

int match_theatre_and_movies(char *string_p)
{
    return (strstr(string_p, "THEATRE") && strstr(string_p, "MOVIES"));
}

int match_trucks_or_chess(char *string_p)
{
    return (strstr(string_p, "TRUCKS") || strstr(string_p, "CHESS"));
}

int match_no_workout(char *string_p)
{
    return (!strstr(string_p, "WORKING OUT"));
}

void string_to_upper(char (*string_p) [80], int size)
{
    int i = 0;
    int k;
    int new_char = 0;
    for (i = 0; i < size; i++) {
        k = 0;
        /*printf("START: %i\n", i);*/
        while (string_p[i][k]) {
            new_char = toupper(string_p[i][k]);
            string_p[i][k] = new_char;
            /*printf("%c", (char)new_char);*/
            k++;
        }
        /*puts("");
        printf("%s\n", string_p[i]);
        puts("DONE\n");
        */
    }
}

/* find sports fans who don't like bieber */
void find(int (*match)(char *), char (*string_p) [80], int size)
{
    int i;
    puts("Search results:");
    puts("-------------------------");

    for (i = 0; i < size; i++) {
        if (match(string_p[i])) {
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

    string_to_upper(ADS, NUM_ADS);
    find(match_sports_no_bieber, ADS, NUM_ADS);
    find(match_theatre_and_movies, ADS, NUM_ADS);
    find(match_trucks_or_chess, ADS, NUM_ADS);
    find(match_no_workout, ADS, NUM_ADS);

    return 0;
}
