#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;

  // fork a child process
  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork Failed\n");
    return 1;
  } else if (pid == 0) {
    printf("I am the child %d\n", pid);
    execlp("/bin/ls", "ls", NULL);
  } else {
    printf("I am the parent %d\n", pid);
    wait(NULL);
    printf("Child Complete\n");
  }

  return 0;
}
