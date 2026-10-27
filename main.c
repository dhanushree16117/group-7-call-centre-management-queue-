#include <stdio.h>
#include <string.h>

#define MAX 5

struct Call {
    int id;
    char name[50];
    char issue[100];
};

struct Call queue[MAX];
int front = 0, rear = -1, count = 0;

// Add a new call
void receiveCall() {
    if (count == MAX) {
        printf("\nCall queue is full.\n");
        return;
    }

    struct Call c;

    printf("Enter Call ID: ");
    scanf("%d", &c.id);

    // Check for duplicate Call ID
    for (int i = 0; i < count; i++) {
        int pos = (front + i) % MAX;
        if (queue[pos].id == c.id) {
            printf("Call ID already exists.\n");
            return;
        }
    }

    printf("Enter customer name: ");
    scanf(" %49[^\n]", c.name);

    printf("Enter customer issue: ");
    scanf(" %99[^\n]", c.issue);

    rear = (rear + 1) % MAX;
    queue[rear] = c;
    count++;

    printf("Call added to the queue.\n");
}

// Answer the next call
void answerCall() {
    if (count == 0) {
        printf("\nNo calls waiting.\n");
        return;
    }

    printf("\nCall %d is now being handled.\n",
           queue[front].id);
    printf("Customer: %s\n", queue[front].name);
    printf("Issue: %s\n", queue[front].issue);

    front = (front + 1) % MAX;
    count--;
}

// Display waiting calls
void displayCalls() {
    if (count == 0) {
        printf("\nNo calls waiting.\n");
        return;
    }

    printf("\n--- Waiting Calls ---\n");

    for (int i = 0; i < count; i++) {
        int pos = (front + i) % MAX;

        printf("\nCall ID: %d\n", queue[pos].id);
        printf("Customer: %s\n", queue[pos].name);
        printf("Issue: %s\n", queue[pos].issue);
    }
}

// Search for a call
void searchCall() {
    int id, found = 0;

    printf("Enter Call ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        int pos = (front + i) % MAX;

        if (queue[pos].id == id) {
            printf("\nCall found!\n");
            printf("Call ID: %d\n", queue[pos].id);
            printf("Customer: %s\n", queue[pos].name);
            printf("Issue: %s\n", queue[pos].issue);
            printf("Position in queue: %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Call not found in waiting queue.\n");
}

// Count waiting calls
void countCalls() {
    printf("\nNumber of waiting calls: %d\n", count);
}

int main() {
    int choice;

    do {
        printf("\n===== CALL CENTRE MANAGEMENT SYSTEM =====\n");
        printf("1. Receive New Call\n");
        printf("2. Answer Next Call\n");
        printf("3. Display Waiting Calls\n");
        printf("4. Search for a Call\n");
        printf("5. Count Waiting Calls\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                receiveCall();
                break;

            case 2:
                answerCall();
                break;

            case 3:
                displayCalls();
                break;

            case 4:
                searchCall();
                break;

            case 5:
                countCalls();
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}