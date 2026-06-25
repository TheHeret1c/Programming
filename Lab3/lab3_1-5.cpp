#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Функция добавления элемента в конец списка
void append(Node** head, Node** tail, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Если список пуст
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    // Если в списке уже есть элементы
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
}

// Прямой обход
void printForward(Node* head) {
    printf("Forward traversal: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Обратный обход
void printBackward(Node* tail) {
    printf("Backward traversal: ");
    Node* current = tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Очистка памяти
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    append(&head, &tail, 10);
    append(&head, &tail, 20);
    append(&head, &tail, 30);
    append(&head, &tail, 40);

    printForward(head);
    printBackward(tail);

    freeList(head);

    return 0;
}