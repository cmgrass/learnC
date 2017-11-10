#include <stdio.h>

/*
  NOTE: You can redirect Standard Input by:
  `./geo2json < gpsdata.csv`
  (This way `scanf()` reads from a file instead of console)

  NOTE: You can redirect Standard Output by:
  `./geo2json > output.json`

  NOTE: You can redirect Standard Error by:
  `./geo2json 2> error.txt`

  Example: `./geo2json < gpsdata.csv > output.json 2> error.txt`
*/

int main()
{
    float latitude = 0;
    float longitude = 0;
    char info[80] = {0};
    int started = 0;

    puts("data=[");

    /* Get float, float, and every character up till enter pressed (max 79) */
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        if (started) {
            printf(",\n");
        } else {
            started = 1;
        }

        /* Validate */
        if ((latitude < -90) || (latitude > 90)) {
            fprintf(stderr, "ERROR - Invalid latitude: %f\n", latitude);
            return 2;    /* Cool!!! This will exit from main()!!! */
                         /* NOTE: You can check error status at console with
                            `echo $?` */
        }

        if ((longitude < -180) || (longitude > 180)) {
            fprintf(stderr, "ERROR - Invalid longitude: %f\n", longitude);
            return 2;
        }

        printf("{latitude: %f, longitude: %f, info: '%s'}",
               latitude, longitude, info);
    }
    puts("\n]");

    return 0;
}
