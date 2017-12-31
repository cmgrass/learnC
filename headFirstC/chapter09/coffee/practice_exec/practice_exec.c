#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void print_err()
{
  fprintf(stderr, "Can't run python program: %d, %s\n", errno,
          strerror(errno));
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
      print_err();
      return 1;
    }
  } else if (pid == -1) {
    /* error */
    print_err();
    return 1;
  } else {
    /* parent active */
  }

  puts("Well, that was easy. Let's try a tougher one");

  if (execl("/usr/bin/python", "/usr/bin/python",
      "../../../../../learnPython/ex43/gameMain.py", NULL) == -1) {
    print_err();
    return 1;
  }

  puts("We did it!");

  return 0;
}
