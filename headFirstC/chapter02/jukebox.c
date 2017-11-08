#include <stdio.h>
#include <string.h>

void practice_strstr()
{
    const char *myNeedle = "worl";
    char bacon[] = "Hello worldz.";
    float precision[] = {1.2542, 253.0023, 2432.3};
    int dudeBro[] = {0, 2, 99, 3, 107, 106, 48};
    char *substringLocation = strstr(bacon, myNeedle);

    if (substringLocation) {
        puts("We found it, aw yeah!");
    } else {
        puts("I couldn't find it!!!");
    };

    printf("Char array size expecting: %lu, actual: %lu\n",
           (14 * sizeof(char)), sizeof(bacon));

    printf("Float array size expecting: %lu, actual: %lu\n",
           (3 * sizeof(float)), sizeof(precision));

    printf("Int array size expecting: %lu, actual: %lu\n",
           (7 * sizeof(int)), sizeof(dudeBro));

    printf("Start of bacon: %p, location of substring: %p\n",
           bacon, substringLocation);

    printf("Does it take string literal as arg? Src: %p, Target: %p\n",
           bacon, strstr(bacon, "lo w"));

    puts("\n\n");
}

void prompt(char *msg)
{
    puts(msg);
    printf("> ");
}

void find_track(char strArray[][80], char *stringToFind)
{
    int i = 0;
    for (i = 0; i < 5; i++) {
        if (strstr(strArray[i], stringToFind)) {
            printf("Track %i is: %s\n", i, strArray[i]);
        }
    }
}

int main()
{
    char trackList[][80] = {
        "I left my heart in Harvard Med School",
        "Newark, Newark - a wonderful town",
        "Dancing with a Dork",
        "From here to maternity",
        "The girl from Iwo Jima",
    };

    char userTrack[80] = {0};

    /* I was using this to experiment with strstr() */
    practice_strstr();

    /* Start actual program */
    prompt("Search for a song title:");
    fgets(userTrack, 80, stdin);
    userTrack[strlen(userTrack) - 1] = '\0';    /* Turn `\n` into `\0` */
    find_track(trackList, userTrack);

    return 0;
}
