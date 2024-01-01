#include <stdio.h>

#define MAX_SIZE 5


void insert(int queue[], int *front, int *rear, int value);
void delete(int queue[], int *front, int *rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;
    int choice, value;

    do {
        printf("\nCircular Queue Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(queue, &front, &rear, value);
                break;
            case 2:
                delete(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void insert(int queue[], int *front, int *rear, int value) {

    if ((*rear + 1) % MAX_SIZE == *front) {
        printf("Queue Overflow. Cannot insert element.\n");
    } else {
    
        if (*front == -1) {
            *front = 0;
        }
        *rear = (*rear + 1) % MAX_SIZE;
        queue[*rear] = value;
        printf("Element %d inserted successfully.\n", value);
    }
}

void delete(int queue[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue Underflow. Cannot delete element.\n");
    } else {
        printf("Element %d deleted successfully.\n", queue[*front]);
        if (*front == *rear) {
            *front = -1;
            *rear = -1;
        } else {
            *front = (*front + 1) % MAX_SIZE;
        }
    }
}

void display(int queue[], int front, int rear) {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the circular queue: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}
