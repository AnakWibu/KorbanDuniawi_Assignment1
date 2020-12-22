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
 
int GetN(struct Node* head, int n) 
{ 
    if(head == NULL)
    { 
      return -1;
    } 
    int count = 0; 
  
    if (count == n) 
    {
        return head->value; 
    }

    return GetN(head->next, n - 1); 
} 
 
int main() 
{ 
    struct Node* head = NULL; 
    push(&head, 1); 
    push(&head, 4); 
    push(&head, 1); 
    push(&head, 12); 
    push(&head, 1); 
    printf("Element di indec ke 1 adalah %d", GetN(head, 1)); 
    getchar(); 
    return 0;
}