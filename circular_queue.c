#include <stdio.h>
#define SIZE 5

int front = -1;
int rear = -1;
int circqueue[SIZE];

// Enqueue function
void enqueue(int item) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1) { // First element being added
            front = 0;
        }
        rear = (rear + 1) % SIZE; // Update rear circularly
        circqueue[rear] = item;
    }
}

// Dequeue function
int dequeue() {
    int store;
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;  // Indicating empty queue
    } else {
        store = circqueue[front];
        if (front == rear) {
            // Only one element was present
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE; // Update front circularly
        }
        return store;
    }
}

// Display function
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue elements:\n");
    if (front <= rear) {
        while (i <= rear) {
            printf("%d\n", circqueue[i]);
            i++;
        }
    } else {
        while (i < SIZE) {
            printf("%d\n", circqueue[i]);
            i++;
        }
        i = 0;
        while (i <= rear) {
            printf("%d\n", circqueue[i]);
            i++;
        }
    }
}

int main() {
    int num, c;
    do {
        printf("Enter choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                num = dequeue();
                if (num != -1) {
                    printf("Dequeued: %d\n", num);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (c != 4);

    return 0;
}
