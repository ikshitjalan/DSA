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

bool search(Node* root,int data){
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<=root->data) return search(root->left,data);
    else return search(root->left,data);}


int main(){
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    Inorder(root);
    
    int number;
    cout<< endl;
    cout<<"Enter the number you want to search:"<<endl;
    cin>>number;
    
    if(search(root,number)==true) cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
    return 0;
}