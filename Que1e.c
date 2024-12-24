#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertAtBeginning(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void displayList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtEnd(30);

    printf("The Linked List which are Inserted :\n");
    displayList();

    return 0;
}
