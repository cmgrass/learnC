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
//  if (execl("/usr/bin/python", "/usr/bin/python",
//      "./test.py", NULL) == -1) {
//    print_err();
//    return 1;
//  }
//
//  puts("Well, that was easy. Let's try a tougher one");

  if (execl("/usr/bin/python", "/usr/bin/python",
      "../../../../../learnPython/ex43/gameMain.py", NULL) == -1) {
    print_err();
    return 1;
  }

  puts("We did it!");

  return 0;
}
