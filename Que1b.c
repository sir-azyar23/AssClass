#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

// Push operation
void push(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }

    struct node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Display stack
void displayStack() {
    struct node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Initial stack:\n");
    displayStack();

    printf("Popped value: %d\n", pop());
    printf("Stack after pop:\n");
    displayStack();

    return 0;
}
