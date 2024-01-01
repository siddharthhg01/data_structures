#include <stdio.h>

#define MAX_SIZE 10

void insert(int queue[], int *rear, int item);
void delete (int queue[], int *front, int rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;
    int choice, item;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insert(queue, &rear, item);
                break;
            case 2:
                delete(queue, &front, rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("Quitting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
void insert(int queue[], int *rear, int item) {
    if (*rear == MAX_SIZE - 1) {
        printf("Queue Overflow! Cannot insert element.\n");
        return;
    }

    if (*rear == -1) {

        *rear = 0;
        queue[*rear] = item;
        printf("Element %d inserted into the queue.\n", item);
    } else {
        (*rear)++;
        queue[*rear] = item;
        printf("Element %d inserted into the queue.\n", item);
    }
}

void delete(int queue[], int *front, int rear) {
    if (*front == rear) {
    
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }

    printf("Element %d deleted from the queue.\n", queue[++(*front)]);
}


void display(int queue[], int front, int rear) {
    if (front == rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front + 1; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
