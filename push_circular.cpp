#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

void push(Node** node,int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*node);
    Node* temp = (*node);

    if((*node)!=NULL){
         while (temp->next != *node){
                temp = temp->next;  
         }
            
        
        temp->next = newNode;
    }
    else{
        newNode->next = newNode; 
    }
    (*node) = newNode;
}
void printList(Node *head)  
{  
    Node *temp = head;  
    if (head != NULL)  
    {  
        do
        {  
            cout << temp->data << " ";  
            temp = temp->next;  
        }  
        while (temp != head);  
    }  
}  
  

int main()  
{  

    Node *head = NULL;  
    push(&head, 12);  
    push(&head, 56);  
    push(&head, 2);  
    push(&head, 11);  
  
    cout << "Contents of Circular Linked List\n ";  
    printList(head);  
  
    return 0;  
}  