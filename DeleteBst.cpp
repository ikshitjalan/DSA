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

Node* findMin( Node* root) 
{ 
	
	if (root == NULL) 
	    return root; 

	
	root->left = findMin(root->left); 
	 
	return root; 
} 

// Node* findMin( Node* root) {
// 	if(root == NULL) return NULL;
// 	while(root->left != NULL)
// 		root = root->left;
// 	return root;
// }

Node* Delete(Node* root, int data){
    if(root==NULL){
        return root;
    }
    else if(data < root->data) root->left = Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);
    else{
        if((root->left==NULL)&&(root->right==NULL)){
            delete root;
            root = NULL;
            return root;
        }
        else if(root->right==NULL){
            Node* temp = root;
            root = root->left;
            delete temp ;
            return root;
        }
        else if(root->left==NULL){
            Node* temp = root;
            root = root->right;
            delete temp ;
            return root;
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
            return root;
        }
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
    Inorder(root);
    cout<<endl;
    Node* newroot = Delete(root,15);
    Inorder(newroot);
    return 0;
}