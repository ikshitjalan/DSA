#include <iostream>
#include <cmath>
using namespace std;

typedef struct  Node{
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
    Node* temp = (node);

    do{
        cout<<" "<<temp->data;
        temp = temp->next;
    }while(temp!=(node));
}

void Split(Node* node,Node** head1,Node** head2){
    Node* temp = (node);
    
    if(temp!=NULL){
        int count = 0;
        
        do{
            temp = temp->next;
            count++;
        }while((temp)!=node);
    
        if(count%2==0){
            Node* temp1 = (node);
            (*head1) = temp1;
            Node* temp3 = (*head1);
            
            for(int i=1;i<count/2;i++){
                
                temp1 = temp1->next;
                temp3->next = temp1;
                temp3 = temp3->next;
                
                
            }
            Node* temp2= (temp3)->next;
            
            (temp3)->next = (*head1);
            
            (*head2) = temp2;
            Node* temp4 = (*head2);
            for(int i=count/2;i<(count-1);i++){
                
                temp2 = temp2->next;
                temp4->next=temp2;
                temp4 = temp4->next;

            }
            (temp4)->next = (*head2);
            
        }else{
            Node* temp1 = (node);
            (*head1) = temp1;
            Node* temp3 = (*head1);
            
            for(int i=1;i<(ceil(count/2));i++){
                // cout<<" "<<i<<endl;
                temp1 = temp1->next;
                temp3->next = temp1;
                temp3 = temp3->next;   
            }

            Node* temp2= (temp3)->next;
            
            (temp3)->next = (*head1);
            
            (*head2) = temp2;
            
            Node* temp4 = (*head2);
            for(int i=((ceil(count/2))+1);i<(count);i++){
                
                temp2 = temp2->next;
                temp4->next=temp2;
                temp4 = temp4->next;

            }
            (temp4)->next = (*head2);
        }
        
    }
    else{
    cout<<"s";
    (*head1)->next = (*head1);
    (*head2)->next = (*head2);

}

}

int main(){
    int list_size, i;  
          
    
    Node *head = NULL;  
    Node *head1 = NULL;  
    Node *head2 = NULL;  
      
    
    push(&head, 12);  
    push(&head, 56);  
    push(&head, 5); 
    push(&head, 6);  
    push(&head, 7);   
    push(&head, 8);   
    
    
      
    cout << "Original Circular Linked List";  
    printList(head);      
      
    
    Split(head, &head1, &head2);  
      
    cout << "\nFirst Circular Linked List";  
    printList(head1);  
      
    cout << "\nSecond Circular Linked List";  
    printList(head2);  
    
    return 0;
}