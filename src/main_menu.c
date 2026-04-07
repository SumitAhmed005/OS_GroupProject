// Main Menu
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    while (1) {
        printf("\n===== Main Menu =====\n");
        printf("1. Logger\n");
        printf("2. File Management\n");
        printf("3. Peterson Solution\n");
        printf("4. Amdahl's Law\n");
        printf("5. Memory Allocation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Logger module started and is waiting for messages.\n");
                system("./logger");
                break;

            case 2:
                system("./file_management");
                break;

            case 3:
                system("./peterson");
                break;

            case 4:
                system("./amdahl");
                break;

            case 5:
                system("./memory");
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
