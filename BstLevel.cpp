#include<iostream>
#include<queue>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* newNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;

}

Node* Insert(Node* root,int data){
    if(root==NULL){
        root = newNode(data);
    }
    else if(data<=root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;

}

void level(Node* root){
    if(root==NULL)  return;
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        cout<<" "<<current->data<<endl;
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
        q.pop();
    }
}

int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    
    level(root);
    return 0;

}