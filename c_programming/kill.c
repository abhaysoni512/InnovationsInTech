#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child running with PID: %d\n", getpid());
        // Keep child alive to give parent time to send signal
        while (1) {
            sleep(1);
        }
    }
    else {
        // Parent process
        printf("Parent will send SIGKILL to child (PID: %d)\n", pid);
        sleep(3); // give child time to start
        if (kill(pid, SIGKILL) == 0) {
            printf("Sent SIGKILL to child.\n");
        } else {
            perror("kill failed");
        }

        // Wait for child to terminate
        waitpid(pid, &status, 0);

        if (WIFSIGNALED(status)) {
            printf("Child terminated due to signal: %d\n", WTERMSIG(status));
        }
    }

    return 0;
}
