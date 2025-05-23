#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("Child: My ID is %d\n", getpid());
        printf("Child: Replacing process with 'ls -l'\n");

        // Replace child process with ls command
        execlp("ls", "ls", "-l", NULL);

        // If exec fails
        perror("exec failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent: My ID is %d\n", getpid());
        printf("Parent: Waiting for child to complete...\n");

        int status;
        wait(&status);

        printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}

