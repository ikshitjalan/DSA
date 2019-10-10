#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* newNode(int newData){
    Node* new_Node  = new Node();
    new_Node->data = newData;
    new_Node->right = NULL;
    new_Node->left = NULL;
    return new_Node;
}

void printInorder(Node* node){

    if(node==NULL){
        return;
    }

    printInorder(node->left);
    cout<<" "<<node->data;
    printInorder(node->right);
    
}

void printpostorder(Node* node){

    if(node==NULL){
        return ;
    }

    printpostorder(node->left);
    printpostorder(node->right);
    cout<<" "<<node->data;
}

void printpreorder(Node* node){

    if(node==NULL){
        return ;
    }
    cout<<" "<<node->data;
    printpreorder(node->left);
    printpreorder(node->right);
    
}

int main(){
    Node *root = newNode(1); 
    root->left             = newNode(2); 
    root->right         = newNode(3); 
    root->left->left     = newNode(4); 
    root->left->right = newNode(5);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printpreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printpostorder(root); 
  
    return 0; 

    }