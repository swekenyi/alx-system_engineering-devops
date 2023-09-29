#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        pid_t child_pid = fork();

        if (child_pid == 0) {
            // Child process
            exit(0);
        } else if (child_pid > 0) {
            // Parent process
            printf("Zombie process created, PID: %d\n", child_pid);
        } else {
            perror("Fork error");
            exit(1);
        }
    }

    // Infinite loop to keep the program running
    while (1) {
        sleep(1);
    }

    return (0);
}

