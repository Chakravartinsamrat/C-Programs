#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Circular queue structure
struct CircularQueue {
    struct Node* header;
};

// Function to initialize an empty circular queue with a header node
void initializeQueue(struct CircularQueue* queue) {
    queue->header = (struct Node*)malloc(sizeof(struct Node));
    if (queue->header == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    queue->header->next = queue->header; // Circular linking
    queue->header->data = 0; // Initialize count to 0
    queue->header->next = NULL; // Initialize next to NULL
}

// Function to enqueue an integer value into the circular queue
void enqueue(struct CircularQueue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = queue->header->next;
    queue->header->next = newNode;
    queue->header->data++; // Increment count

    // Update largest and smallest values
    if (queue->header->data == 1 || value > queue->header->next->data) {
        queue->header->next->data = value; // Update largest
    }
    if (queue->header->data == 1 || value < queue->header->next->data) {
        queue->header->next->next->data = value; // Update smallest
    }
}

// Function to dequeue an element from the circular queue
void dequeue(struct CircularQueue* queue) {
    if (queue->header->data == 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = queue->header->next;
    queue->header->next = temp->next;
    free(temp);
    queue->header->data--; // Decrement count

    // If the dequeued element was the largest or smallest, update accordingly
    if (queue->header->data > 0) {
        int largest = queue->header->next->data;
        int smallest = queue->header->next->data;

        struct Node* current = queue->header->next->next;
        for (int i = 1; i < queue->header->data; i++) {
            if (current->data > largest) {
                largest = current->data;
            }
            if (current->data < smallest) {
                smallest = current->data;
            }
            current = current->next;
        }

        queue->header->next->data = largest;
        queue->header->next->next->data = smallest;
    }
}

// Function to retrieve the largest value from the circular queue
int getLargestValue(struct CircularQueue* queue) {
    if (queue->header->data == 0) {
        printf("Queue is empty. No largest value.\n");
        exit(EXIT_FAILURE);
    }
    return queue->header->next->data;
}

// Function to retrieve the smallest value from the circular queue
int getSmallestValue(struct CircularQueue* queue) {
    if (queue->header->data == 0) {
        printf("Queue is empty. No smallest value.\n");
        exit(EXIT_FAILURE);
    }
    return queue->header->next->next->data;
}

// Function to display the elements of the circular queue, starting from the front
void displayQueue(struct CircularQueue* queue) {
    if (queue->header->data == 0) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->header->next;
    for (int i = 0; i < queue->header->data; i++) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the circular queue
void freeQueue(struct CircularQueue* queue) {
    while (queue->header->next != queue->header) {
        struct Node* temp = queue->header->next;
        queue->header->next = temp->next;
        free(temp);
    }
    free(queue->header);
}

int main() {
    struct CircularQueue myQueue;
    initializeQueue(&myQueue);

    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Largest Value\n");
        printf("4. Get Smallest Value\n");
        printf("5. Display Queue\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                printf("Enqueued %d\n", value);
                break;

            case 2:
                dequeue(&myQueue);
                printf("Dequeued\n");
                break;

            case 3:
                printf("Largest value: %d\n", getLargestValue(&myQueue));
                break;

            case 4:
                printf("Smallest value: %d\n", getSmallestValue(&myQueue));
                break;

            case 5:
                printf("Queue elements: ");
                displayQueue(&myQueue);
                break;

            case 6:
                freeQueue(&myQueue);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
