#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int value;
    struct Node* next;
};

void push(struct Node** head, int value)
{
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}
 
int detectLoop(struct Node* list)
{
    struct Node *slow = list, *fast = list;
 
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

void printList(struct Node* head)
{
    struct Node* curr = head;
    while (curr)
    {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
 
    printf("NULL\n");
}
 
int main()
{
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    head->next->next->next->next = head;

    if (detectLoop(head))
    {
        printf("Loop found\n");
    }
    else
    {
        printf("No Loop\n");
    }
    return 0;
}