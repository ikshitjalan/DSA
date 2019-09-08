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
    (*node)=newNode; 

}

bool search(Node* node,int key){
    Node* temp = node;
    while(temp!=NULL)
    {
        if(temp->data==key){
        return true ;}
        temp = temp->next;
    }
    
            
    
    
        return false;
    
    
        
    }

int main(){
    Node* head = NULL;  
    int x = 20;  
  
    /* Use push() to construct below list  
    14->21->11->30->10 */
    push(&head, 10);  
    push(&head, 30);  
    push(&head, 11);  
    push(&head, 21);  
    push(&head, 14);  
  
    search(head, x)?cout<<"Yes":cout<<"No" ;
    return 0;  
    
}