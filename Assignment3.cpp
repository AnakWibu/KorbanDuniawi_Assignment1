#include<stdio.h>  
#include<stdlib.h>  

struct Node  
{  
    int value;  
    struct Node* next;  
};  
  
void printMiddle(struct Node *head)  
{  
    struct Node *slow = head;  
    struct Node *fast = head;  
  
    if (head!=NULL)  
    {  
        while (fast != NULL && fast->next != NULL)  
        {  
            fast = fast->next->next;  
            slow = slow->next;  
        }  
        printf("Middle Element is [%d]\n", slow->value);  
    }  
}  
  
void push(struct Node** head, int value)  
{
    struct Node* newNode =  (Node*) malloc(sizeof(Node));  
    newNode->value = value;  
    newNode->next = *head;  
    *head = newNode;  
}  
    
void printList(struct Node* head)  
{  
    Node *curr = head;
    while (curr)  
    {  
        printf("%d->", curr->value);  
        curr = curr->next;  
    }  
    printf("NULL\n");  
}  
  

int main()  
{  
    struct Node* head = NULL;  
  
    for (int i=5; i>0; i--)  
    {  
        push(&head, i);  
        printList(head);  
        printMiddle(head);  
    }  
  
    return 0;  
}  