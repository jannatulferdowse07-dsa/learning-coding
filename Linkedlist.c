#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next; 
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList *creatlinkedlist() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insert(int value, int position, LinkedList *list) {
    if (position < 0 || position > list->size) {
        printf("Invalid position!\n");
        return;
    }

    Node *node = createNode(value);

    if (position == 0) {
        node->next = list->head;
        list->head = node;
        if (list->size == 0) {
            list->tail = node;
        }
    }
    else if (position == list->size) {
        list->tail->next = node;
        list->tail = node;
    }
    else {
        Node *curr = list->head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
    }

    list->size++;
}

int main() {
    LinkedList *myList = creatlinkedlist();
    
    insert(10, 0, myList);
    insert(20, 1, myList);
    insert(15, 1, myList);
    
    Node *temp = myList->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
