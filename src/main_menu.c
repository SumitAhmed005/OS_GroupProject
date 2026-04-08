// Main Menu
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    while (1) {
        printf("\n===== Main Menu =====\n");
        printf("1. File Management\n");
        printf("2. Peterson Solution\n");
        printf("3. Amdahl's Law\n");
        printf("4. Memory Allocation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                system("./file_management");
                break;

            case 2:
                system("./peterson");
                break;

            case 3:
                system("./amdahl");
                break;

            case 4:
                system("./memory");
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
