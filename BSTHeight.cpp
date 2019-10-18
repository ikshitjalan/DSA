#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* newNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* Insert(Node* root,int data){
    if(root == NULL){
        root = newNode(data);
        
    }else if(data<=root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}

void Inorder(Node* root){
    if(root==NULL){
        return;
    }else{
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

int height(Node* root){
    if(root==NULL){
        return -1;
    }
    
        int leftheight = height(root->left);

        int rightheight = height(root->right);
    
    return( max(leftheight,rightheight)+1);
        
    
}

int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,28);
    root = Insert(root,29);
    root = Insert(root,30);
    Inorder(root);
    int high = height(root);
    cout<<endl<<"Height: "<<high<<endl;
    return 0;
}