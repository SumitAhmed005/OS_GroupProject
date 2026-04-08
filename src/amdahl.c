//Amdahl Module
#include <stdio.h>
#include <time.h>

// logger function
void log_action(const char *action) {
    FILE *log = fopen("../logs/logs.txt", "a");
    if (log == NULL) return;

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
    double P;   // Parallel portion
    int N;      // Number of processors
    double speedup;

    printf("=== Amdahl's Law Module ===\n");
    log_action("Amdahl module started");

    // User Input
    printf("Enter parallel fraction (0 to 1): ");
    scanf("%lf", &P);

    printf("Enter number of processors: ");
    scanf("%d", &N);

    log_action("User input received");

    // P must be between 0 and 1 and N must be positive or else the program stops
    if (P < 0 || P > 1 || N <= 0) {
        printf("Invalid input. Please try again.\n");
        log_action("Invalid input in Amdahl module");
        return 1;
    }

    // Amdahl's Law formula
    speedup = 1 / ((1 - P) + (P / N));

    // Output
    printf("Speedup: %.4f\n", speedup);
    log_action("Speedup calculated successfully");

    return 0;
}
