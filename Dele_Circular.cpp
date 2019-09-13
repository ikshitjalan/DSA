#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;

}Node;

void push(Node** node,int newData){
    Node* newNode = new Node();
    Node* temp = (*node);
    newNode->data = newData;
    newNode->next = (*node);
    if((*node)!=NULL){
        do{
        temp=temp->next;

    }while(temp->next!=(*node));
    temp->next = newNode;
    }
    else{
        newNode->next = newNode;
    }
    
    (*node) = newNode;

}

void printList(Node* node){
    Node* temp = node;
    if(node!=NULL){
        do{
        cout<<" "<<temp->data;
        temp = temp->next;
    }while(temp!=node);

    }
    
}

void deleteEven(Node** node){
    if((*node)!=NULL){
        Node* prev = (*node);
        int count = 1;
        do{
            prev = prev->next;
            count++;
            
        }while(prev->next!=(*node));
        Node* temp1 = (*node);
        Node* temp = (*node);
        for(int i=1;i<=count;i++){
            if((temp==(*node))&&((temp->data)%2==0)){
                temp1 = temp->next;
                prev->next = temp1;
                temp = temp1;
                temp1 = NULL;
                (*node) = prev->next;
                
                
            }else if((temp!=(*node))&&((temp->data)%2==0)){
                
                temp1 = temp->next;
                prev->next = temp1;
                temp = temp1;
                temp1 = NULL;
                
                
            }else{
                temp = temp->next;
                prev = prev->next;
                
            }
            
        }
        
    }
}
int main(){
    Node* head = NULL; 
  
    // Created linked list will be 4->57->11->2->56->12->61 
    push(&head, 61); 
    push(&head, 12); 
    push(&head, 56); 
    push(&head, 2); 
    push(&head, 11); 
    push(&head, 57);
    push(&head, 4);  
    
  
    cout << "\nList after deletion : "; 
    deleteEven(&head); 
    printList(head); 
  
    return 0; 
}