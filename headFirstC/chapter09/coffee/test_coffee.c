#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char *my_env[] = {"FOOD=coffee", NULL};

  if (execle("./coffee", "./coffee", "burrrritoe", NULL, my_env)) {
    fprintf(stderr, "Can't create order: %s\n", strerror(errno));
    return 1;
  }
  return 0;
}
