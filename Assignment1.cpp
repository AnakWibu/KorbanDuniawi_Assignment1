#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int value;
    struct Node* next;
};
 
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
 

void push(struct Node** head, int value)
{
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    if (a == NULL)
        return b;
 
    else if (b == NULL)
        return a;
 
    struct Node* result = NULL;
 
    if (a->value <= b->value)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}
 
int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Node *a = NULL, *b = NULL;
    for (int i = n - 1; i >= 0; i = i - 2)
    {
        push(&a, arr[i]);
    }
    for (int i = n - 2; i >= 0; i = i - 2)
    {
        push(&b, arr[i]);
    }
    printf("Linked List a  :  ");
    printList(a);
 
    printf("Linked List b : ");
    printList(b);
 
    struct Node* head = SortedMerge(a, b);
    printf("Sesudah di sorting : ");
    printList(head);
 
    return 0;
}
