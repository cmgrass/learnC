#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void print_err(char *msg)
{
  fprintf(stderr, "%s: %d, %s\n", msg, errno,
          strerror(errno));
  exit(1);
}

int main(int argc, char *argv[])
{
  pid_t pid = fork();

  /* Fork the parent to create a child that can execute our python script */
  /* This way the parent can continue, because `exec()` functions cause */
  /* the origin process to terminate. We sacrifice the child. */
  if (!pid) {
    /* child active */
    if (execl("/usr/bin/python", "/usr/bin/python",
        "./test.py", NULL) == -1) {
      print_err("Can't run python program");
    }
  } else if (pid == -1) {
    /* error */
    print_err("Can't fork the parent process");
  } else {
    /* parent active */
  }

  puts("Well, that was easy. Let's try a tougher one");

  if (execl("/usr/bin/python", "/usr/bin/python",
      "../../../../../learnPython/ex43/gameMain.py", NULL) == -1) {
    print_err("Can't run the python process");
  }

  puts("We did it!");

  return 0;
}
