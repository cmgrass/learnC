#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch = '\0';

    if (argc <= 1) {
        puts("ERROR: Invalid number of arguments");
        return 1;
    }

    while ((ch = getopt(argc, argv, "d:t")) != EOF) {
        switch (ch) {
          case 'd':
              /*
                Optarg points to the argument supplied
                with the option. I'm guessing it makes
                a permanent copy of the argument at some
                address before the optarg pointer moving
                on to the next one.
                Here, we are saying point to the argument.
              */
              delivery = optarg;
              break;
          case 't':
              thick = 1;
              break;
          default:
              fprintf(stderr, "Unknown option: '%s'\n", optarg);
              return 1;
        }

        printf("~~~monitoring~~~ option (ch): %c, optarg:%s, optind:%d\n",
               ch, optarg, optind);

    }

    argc -= optind;    /* opting stores number of strings read by getopt() */
    argv += optind;

    if (thick) {
        puts("Thick crust.");
    }

    if (delivery[0]) {
        printf("To be delivered %s.\n", delivery);
    }

    puts("Ingredients:");

    for (count = 0; count < argc; count ++) {
        puts(argv[count]);
    }

    return 0;
}
