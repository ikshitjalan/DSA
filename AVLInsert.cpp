#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node*  right;
    int height;
}Node;

Node* newNode{
    Node* new_Node = new  Node();
    Node* left =NULL;
    Node* right =NULL;
    int height = 1;
    return new_Node;
}

int height(Node* node){
    if(node==NULL){
        return 0;
    }else{
        height = node->height;
        return height;
    }
}

int max(int a ,int b){
    return (a>b)?a:b;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2  = y->right;

    x->right = y;
    x->left = T2;

    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    
    return x;  
}

Node* leftRotate(Node* x){
    Node* y = x->left;
    Node* T2  = x->right;

    x->right = x;
    x->left = T2;

    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    
    return y;  
}

Node* insert(Node* root,int newData){
    if(root==NULL){
        root->data = newData;
        return(root);
    }
    
    
    }