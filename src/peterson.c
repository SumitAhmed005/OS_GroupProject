//Peterson Module
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>

void log_action(const char *action) {
    FILE *log = fopen("../logs/logs.txt", "a");
    if (log == NULL) {
        return;
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);

    if (timestamp != NULL) {
        timestamp[24] = '\0';
        fprintf(log, "[%s] %s\n", timestamp, action);
    } else {
        fprintf(log, "%s\n", action);
    }

    fclose(log);
}

int main() {
    int *flag = mmap(NULL, 2 * sizeof(int),
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED | MAP_ANONYMOUS,
                     -1, 0);

    int *turn = mmap(NULL, sizeof(int),
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED | MAP_ANONYMOUS,
                     -1, 0);

    if (flag == MAP_FAILED || turn == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    flag[0] = 0;
    flag[1] = 0;
    *turn = 0;

    pid_t p1 = fork();

    if (p1 < 0) {
        perror("fork failed");
        munmap(flag, 2 * sizeof(int));
        munmap(turn, sizeof(int));
        return 1;
    }

    if (p1 == 0) {
        int i = 0;
        int j = 1;

        printf("Process %d: Entry section\n", i);
        log_action("Process 0 entered entry section");

        flag[i] = 1;
        *turn = j;

        while (flag[j] && *turn == j) {
            // busy waiting
        }

        printf("Process %d: Critical section\n", i);
        log_action("Process 0 entered critical section");
        sleep(1);

        printf("Process %d: Exit section\n", i);
        log_action("Process 0 entered exit section");

        flag[i] = 0;
        munmap(flag, 2 * sizeof(int));
        munmap(turn, sizeof(int));
        exit(0);
    }

    pid_t p2 = fork();

    if (p2 < 0) {
        perror("fork failed");
        munmap(flag, 2 * sizeof(int));
        munmap(turn, sizeof(int));
        return 1;
    }

    if (p2 == 0) {
        int i = 1;
        int j = 0;

        printf("Process %d: Entry section\n", i);
        log_action("Process 1 entered entry section");

        flag[i] = 1;
        *turn = j;

        while (flag[j] && *turn == j) {
            // busy waiting
        }

        printf("Process %d: Critical section\n", i);
        log_action("Process 1 entered critical section");
        sleep(1);

        printf("Process %d: Exit section\n", i);
        log_action("Process 1 entered exit section");

        flag[i] = 0;
        munmap(flag, 2 * sizeof(int));
        munmap(turn, sizeof(int));
        exit(0);
    }

    wait(NULL);
    wait(NULL);

    munmap(flag, 2 * sizeof(int));
    munmap(turn, sizeof(int));

    return 0;
}
