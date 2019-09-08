#include <iostream>
using namespace std;

typedef struct  Node{
    
    int data;
    Node* next;
}Node;

Node* newNode(int newData){
    Node* node = new Node();
    node->data = newData;
    node->next = NULL;
    return node;
}

void push(Node** node,int newData){
    Node* newnode = newNode( newData);
    newnode->next = (*node);
    (*node) = newnode;
    
}

void insert(Node** node,int newData,int num){
    Node* newnode = newNode(newData);
    Node* temp = (*node);
    int i = 1;
    while(i!=num){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void append(Node** node,int newData){
    Node* newnode = newNode(newData);
    if((*node) == NULL)
    {
        (*node) = newnode;
    }
    else{
    Node* temp = (*node);
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    }
    
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main(){
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
    insert(&head,3, 2);
    
    cout<<"Created Linked list is: ";
    printList(head);
    
    return 0;
}