#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;


void push(Node** node,int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    Node* temp = (*node);
    newNode->next = (*node);
    if((*node)!=NULL){
        while(temp->next!=(*node)){
        temp = temp->next;
    }
    temp->next = newNode;
    }
    else{
        newNode->next = newNode;
    }
    (*node ) = newNode;
    
    
}


void printList(Node* node){
    if(node!=NULL){
        Node* temp = node;
        do{
            cout<<" "<<temp->data;
            temp = temp->next;
        }while(temp!=node);
    }
}

void reverse(Node** node){
    Node* curr  = (*node);
    Node* prev = (*node);
    Node* Next;
    int count = 1;
    do{
        prev = prev->next;
        count++;
    }while(prev->next!=(*node));
    
    for(int i=1;i<=count;i++){
        
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        
    }
    
    (*node)=prev;
       
}
int main(){
    Node *head = NULL;  
    
      
    
    push(&head, 12);  
    push(&head, 56);  
    push(&head, 5); 
    push(&head, 6);  
    push(&head, 7);   
    push(&head, 8);   
  
    cout << "Given circular linked list: "; 
    printList(head); 
  
    reverse(&head); 
  
    cout << "\nReversed circular linked list: "; 
    printList(head); 
  
    return 0; 

}