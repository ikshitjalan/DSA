#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

void push( Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node(); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

void deleteNode(Node** node,int key){
    if((*node)->data==key){
        Node* temp1 = (*node)->next;
        temp1 =NULL;
        (*node) = ((*node)->next);
    }
    else{
        Node* temp = (*node);
    while((temp->next)->data!=key){
        temp = temp->next;
    }
    Node* temp2 =(temp->next)->next;
    (temp->next)->next = NULL; 
    temp->next = temp2;
    
    }
    
}

void printList( Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<"  "<<node->data; 
        node = node->next; 
    } 
} 
  
int main(){

 
    /* Start with the empty list */
    Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
    
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 3); 
    puts("\nLinked List after Deletion at value 3: "); 
    printList(head); 
    deleteNode(&head, 2); 
    puts("\nLinked List after Deletion at value 2: "); 
    printList(head); 
    deleteNode(&head, 7); 
    puts("\nLinked List after Deletion at value 7: "); 
    printList(head); 
    deleteNode(&head, 8); 
    puts("\nLinked List after Deletion at value 8: "); 
    printList(head); 
    deleteNode(&head, 1); 
    puts("\nLinked List after Deletion at value 1: "); 
    printList(head); 
    return 0; 
} 


