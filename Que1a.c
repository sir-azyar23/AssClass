#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    int priority; 
    char device[20];
    struct node* next;
};

struct node* head = NULL;


void insertRequest(int priority, char* device) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp, *prev;

    newnode->priority = priority;
    strcpy(newnode->device, device);
    newnode->next = NULL;

    
    if (head == NULL || head->priority > priority) {
        newnode->next = head;
        head = newnode;
        return;
    }

   
    temp = head;
    while (temp != NULL && temp->priority <= priority) {
        prev = temp;
        temp = temp->next;
    }

    newnode->next = prev->next;
    prev->next = newnode;
}


void processRequests() {
    struct node* temp;
    while (head != NULL) {
        printf("Processing device: %s with priority: %d\n", head->device, head->priority);
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    insertRequest(3, "Scanner");
    insertRequest(1, "Keyboard");
    insertRequest(4, "Printer");
    insertRequest(2, "Mouse");

    printf("Processing Requests Based On Priority:\n");
    processRequests();

    return 0;
}
