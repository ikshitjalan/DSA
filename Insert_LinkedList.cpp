// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};
void push(Node** head_ref,int new_data){
    if(*head_ref==NULL){
        cout<< ("Linked List doesnot exists\n");
        return;
    }

    Node* new_Node = new Node();
    new_Node->data=new_data;
    new_Node->next=(*head_ref);
    (*head_ref) = new_Node;
}

void insert(Node* prev_Node,int new_data){
    if (prev_Node==NULL){
        cout<<("Linked List doesnot exists\n");
        return  ;
    }
    Node* new_Node = new Node();
    new_Node->data=new_data;
    new_Node->next=prev_Node->next;
    prev_Node->next=new_Node;

}

void append(Node** head_ref,int new_data){
    Node* new_Node = new Node();
    new_Node->data = new_data;
    if ((*head_ref)==NULL){
        new_Node->next = (*head_ref);
        (*head_ref) = new_Node;
        return;
    }
    Node* last = *head_ref;
    while (last->next!=NULL){
        last = last->next;
    }
    last->next=new_Node;
    return;
}

void print(Node* n){
    while(n!=NULL){
        cout<<"  "<<n->data;
        n = n->next;
    }
}


int main(){
     /* Start with the empty list */
    Node* head = NULL;  
      
    // Insert 6. So linked list becomes 6->NULL  
    append(&head, 6);  
      
    // Insert 7 at the beginning.  
    // So linked list becomes 7->6->NULL  
    push(&head, 7);  
      
    // Insert 1 at the beginning.  
    // So linked list becomes 1->7->6->NULL  
    push(&head, 1);  
      
    // Insert 4 at the end. So  
    // linked list becomes 1->7->6->4->NULL  
    append(&head, 4);  
      
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    insert(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    print(head);  
      
    return 0;  

}