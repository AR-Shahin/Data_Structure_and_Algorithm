#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isQueueEmpty() {
    return (front == -1 && rear == -1);
}

bool isQueueFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int data) {
    if (isQueueFull()) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (isQueueEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = data;
}

int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int data = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    return data;
}

void push(int data) {
    enqueue(data);
}

int pop() {
    int i, size = rear - front + 1;
    int popped_element;

    for (i = 0; i < size - 1; i++) {
        enqueue(dequeue());
    }

    popped_element = dequeue();

    return popped_element;
}

int peek() {
    int i, size = rear - front + 1;
    int peeked_element;

    for (i = 0; i < size; i++) {
        enqueue(dequeue());
    }

    peeked_element = queue[front];

    for (i = 0; i < size; i++) {
        enqueue(dequeue());
    }

    return peeked_element;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Peek: %d\n", peek());

    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());

    printf("Peek: %d\n", peek()); // Will return -1 as the stack is empty

    return 0;
}
