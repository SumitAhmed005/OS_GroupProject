//Amdahl Module
#include <stdio.h>

int main() {
    double P;   // Parallel portion
    int N;      // Number of processors
    double speedup;

    printf("=== Amdahl's Law Module ===\n");

    // User Input
    printf("Enter parallel fraction (0 to 1): ");
    scanf("%lf", &P);

    printf("Enter number of processors: ");
    scanf("%d", &N);

    // P must be between 0 and 1 and N must be positive or else the program stops
    if (P < 0 || P > 1 || N <= 0) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Amdahl's Law formula
    speedup = 1 / ((1 - P) + (P / N));

    // Output
    printf("Speedup: %.4f\n", speedup);

    return 0;
}
