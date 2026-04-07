//File Module
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

// Logging function
void log_action(const char *action) {
    FILE *log = fopen("../logs/logs.txt", "a");
    if (log == NULL) return;

    time_t now = time(NULL);
    fprintf(log, "%s - %s\n", ctime(&now), action);

    fclose(log);
}

// Create File
void create_file() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return;
    }

    printf("File created successfully.\n");
    fclose(fp);

    log_action("File created");
}

// Read File
void read_file() {
    char filename[100], ch;

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("\nFile content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
    log_action("File read");
}

// List Files
void list_files() {
    struct dirent *entry;
    DIR *dir = opendir(".");

    if (dir == NULL) {
        printf("Unable to open directory.\n");
        return;
    }

    printf("\nFiles in current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    log_action("Listed files");
}

// Delete File
void delete_file() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
        log_action("File deleted");
    } else {
        printf("Error deleting file.\n");
    }
}

// Main Menu
int main() {
    int choice;

    while (1) {
        printf("\n--- File Management Menu ---\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. List Files\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: create_file(); break;
            case 2: read_file(); break;
            case 3: list_files(); break;
            case 4: delete_file(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
