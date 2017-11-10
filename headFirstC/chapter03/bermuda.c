#include <stdio.h>

/*
  NOTE: You can run this with `geo2json` with the following command:
  `(./bermuda | ./geo2json) < gpsdata.csv > output.json`
  The command connects the two tools with a "pipe" `|`.
  This "pipe" pipse Standard Output from `bermuda` to Standard Input of `geo..`
*/


int main()
{
    float latitude = 0;
    float longitude = 0;
    char info[80] = {0};

    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        if ((latitude > 26) && (latitude < 34)) {
            if ((longitude > -76) && (longitude < -64)) {
                /* This is a valid bermuda coordinate, write it out */
                fprintf(stdout, "%f,%f,%.80s\n", latitude, longitude, info);
            }
        }
    }

    return 0;
}
