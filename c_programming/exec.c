#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec, PID: %d\n", getpid());

    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args);

    // This line runs ONLY if exec fails
    perror("exec failed");
    return 1;
}
