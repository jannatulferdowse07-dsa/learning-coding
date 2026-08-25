#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(int value, Stack *stack) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

int peek(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

int main() {
    Stack *myStack = createStack();

    push(10, myStack);
    push(20, myStack);
    push(30, myStack);

    printf("Top element: %d\n", peek(myStack));

    printf("Popped: %d\n", pop(myStack));
    printf("Popped: %d\n", pop(myStack));

    printf("Top element now: %d\n", peek(myStack));

    return 0;
}
