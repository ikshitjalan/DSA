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
        (*node) = newNode;
        

    
}

int length(Node* node){
    Node* temp = node;
    int count=0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

int main(){
    Node* head = NULL; 
  
    /* Use push() to construct below list 
     1->2->1->3->1  */
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head,4);
    push(&head, 1); 
  
    /* Check the count function */
    
    cout<<length(head)<<endl;
    return 0; 

    
}
