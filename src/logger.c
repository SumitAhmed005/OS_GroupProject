// Logger Module
// Uses fork() and pipe() for IPC
// Child process handles logging to logs/logs.txt
// Parent process sends log messages from other modules
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_timestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", t);
}

// Function to send a log message through pipe
void log_message(int fd, const char *level, const char *msg) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "[%s] [PID:%d] %s", level, getpid(), msg);
    write(fd, buffer, strlen(buffer) + 1);
}

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process: logger
        close(fd[1]);  // Close write end

        FILE *logFile = fopen("../logs/logs.txt", "a");
        if (!logFile) {
            perror("Error opening log file");
            exit(1);
        }

        char buffer[BUFFER_SIZE];
        char timestamp[64];

        while (1) {
            ssize_t bytes = read(fd[0], buffer, BUFFER_SIZE);
            if (bytes > 0) {
                get_timestamp(timestamp);
                fprintf(logFile, "[%s] %s\n", timestamp, buffer);
                fflush(logFile);  // Ensure logs are written immediately
                // Optional: also print to terminal for monitoring
                printf("[LOGGER] %s\n", buffer);
            }
        }
    } else {  // Parent process: other modules will send logs here
        close(fd[0]);  // Close read end
        while (1) {
            pause(); // Wait indefinitely; parent will send logs externally
        }
    }

    return 0;
}
