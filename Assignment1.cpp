#include <stdio.h>
#include <stdlib.h>
 
// Data Structure to store a linked list node
struct Node
{
    int value;
    struct Node* next;
};
 
// Helper function to print given linked list
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
 
// Helper function to insert new Node in the beginning of the linked list
void push(struct Node** head, int value)
{
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    // Base cases
    if (a == NULL)
        return b;
 
    else if (b == NULL)
        return a;
 
    struct Node* result = NULL;
 
    // Pick either a or b, and recur
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
 
// main method
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
    printf("First List  :  ");
    printList(a);
 
    printf("Second List : ");
    printList(b);
 
    struct Node* head = SortedMerge(a, b);
    printf("After Merge : ");
    printList(head);
 
    return 0;
}