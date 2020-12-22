#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void reverse(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void push(struct Node** head, int value)
{
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}
 
void printList(struct Node* head)
{
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL");
}
 
int main()
{
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("Sebelum di Reverse\n");
    printList(head);
    reverse(&head);
    printf("\nSesudah di reverse\n");
    printList(head);
    getchar();
    return 0;
}