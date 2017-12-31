#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game(int sig)
{
  printf("\nFinal Score: %i\n", score);
  exit(0);
}

int catch_signal(int sig, void (*handler)(int))
{
  /* When signal `sig` comes in, run callback `handler` */
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  return sigaction(sig, &action, NULL);
}

void times_up(int sig)
{
  puts("\nTIME'S UP!");
  raise(SIGINT); /* raise interrupt signal to run our handler to end game */
}

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main()
{
  /* setup our signal catchers so we can handle the interrupts our own way */
  catch_signal(SIGINT, &end_game);
  catch_signal(SIGALRM, &times_up);

  /* generate seed for future random numbers */
  srandom(time(0));

  /* run the game */
  while(1) {
    /* Generate random numbers 0 to 10 */
    int a = random() % 11;
    int b = random() % 11;
    char txt[4];
    alarm(5); /* set a five second timer for SIGALRM interrupt */

    printf("\nWhat is %i times %i? ", a, b);
    fgets(txt, 4, stdin);
    int answer = atoi(txt);
    if (answer == (a * b)) {
      score++;
    } else {
      printf("\nWrong! Score: %i\n", score);
    } /* end-if */

  } /* end-while */
  return 0;
}
