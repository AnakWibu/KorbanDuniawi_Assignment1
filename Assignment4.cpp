#include<stdio.h> 
#include<stdlib.h> 
  
struct Node 
{ 
    int value; 
    struct Node* next; 
}; 

void push(struct Node** head, int value)  
{
    struct Node* newNode =  (Node*) malloc(sizeof(Node));  
    newNode->value = value;  
    newNode->next = *head;  
    *head = newNode;  
}  
  
void printList(struct Node *head) 
{ 
    Node *curr = head;
    while (curr!=NULL) 
    { 
       printf("%d ->", curr->value); 
       curr = curr->next; 
    } 
    printf("NULL");
}  
  
 Node* deleteDuplicates(Node* head) { 
        if (head == nullptr) 
            return nullptr; 
        if (head->next == nullptr) 
            return head; 
  
        if (head->value == head->next->value) { 
            Node *tmp; 
            tmp = head->next; 
            head->next = head->next->next; 
            free(tmp); 
            return deleteDuplicates(head); 
        } 
  
        else { 
            head->next = deleteDuplicates(head->next); 
            return head; 
        } 
    } 
  
int main() 
{ 
    struct Node* head = NULL; 
    
    push(&head, 20); 
    push(&head, 13); 
    push(&head, 13);   
    push(&head, 11); 
    push(&head, 11); 
    push(&head, 11);                                     
  
    printf("\n Sebelum Menghilangkan Duplicate : "); 
    printList(head);  
    head = deleteDuplicates(head);  
  
    printf("\n Setelah Menghilangkan Duplicate : ");          
    printList(head);             
    
    return 0; 
} 