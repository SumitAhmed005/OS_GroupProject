//Memory Module
#include <stdio.h>
#include <time.h>

#define MAX 20

int holes[MAX];      // memory blocks
int original[MAX];
int allocated[MAX];  // allocation status (0 = free, 1 = allocated)
int n;               // number of holes

// Logger function
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

// Display memory map
void display() {
    log_action("Display memory map");

    printf("\n Memory Map \n");
    for (int i = 0; i < n; i++) {
        if (allocated[i] == 1)
            printf("Block %d: %d KB [ALLOCATED]\n", i, holes[i]);
        else
            printf("Block %d: %d KB [FREE]\n", i, holes[i]);
    }
}

// First Fit Allocation
void allocate() {
    int size;
    printf("Enter process size: ");
    scanf("%d", &size);

    log_action("Allocate request");

    for (int i = 0; i < n; i++) {
        if (allocated[i] == 0 && holes[i] >= size) {
            printf("Process allocated in block %d\n", i);
            holes[i] -= size;
            allocated[i] = 1;
            log_action("Allocation successful");
            return;
        }
    }
    printf("Allocation failed. No suitable block found.\n");
    log_action("Allocation failed");
}

// Deallocate block
void deallocate() {
    int index;
    printf("Enter block index to free: ");
    scanf("%d", &index);

    if(index < 0 || index >= n || allocated[index] == 0) {
     printf("Invalid block index.\n");
     log_action("Invalid deallocation");
    } else {
     allocated[index] = 0;
     holes[index] = original[index];
     printf("Block %d deallocated.\n", index);
     log_action("Deallocation successful");
    }
}

// Compaction (merge free blocks)
void compact() {
    int newHoles[MAX];
    int newAllocated[MAX];
    int j = 0;

    log_action("Compaction started");

    //moving allocated blocks
    for (int i = 0; i < n; i++) {
        if (allocated[i] == 1) {
            newHoles[j] = holes[i];
            newAllocated[j] =1;
           j++;
        }
    }

    //free blocks
    for (int i = 0; i < n; i++) {
        if (allocated[i] == 0) {
        newHoles[j] = holes[i];
            newAllocated[j] = 0;
         j++;
        }
    }

    for (int i = 0; i < n; i++) {
        holes[i] = newHoles[i];
        allocated[i] = newAllocated[i];
    }
    printf("Memory compacted.\n");
    log_action("Compaction completed");
}

int main() {
    int choice;

    printf(" Memory Management (First Fit + Compaction) \n");
    log_action("Memory module started");

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter size of block %d: ", i);
        scanf("%d", &holes[i]);
        original[i] = holes[i];
        allocated[i] = 0;
    }

    while (1) {
        printf("\n1. Allocate\n2. Deallocate\n3. Display\n4. Compact\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: allocate(); break;
            case 2: deallocate(); break;
            case 3: display(); break;
            case 4: compact(); break;
            case 0: 
                log_action("Program exited");
                return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
