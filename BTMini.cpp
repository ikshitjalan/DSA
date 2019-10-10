#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* right;
    Node* left;
}Node;

Node* newNode(int newData){
    Node* new_Node = new Node();
    new_Node->data = newData;
    new_Node->right = NULL;
    new_Node->left = NULL;
    return new_Node;
}

Node* insert(Node* node,int newData){
    if(node==NULL){
        return(newNode(newData));
    }else{
        
    if(newData<=(node->data)){
        node->left = insert(node->left, newData);
    }else{
        node->right = insert(node->right,newData);
    }
    return(node);
    }

}

int minValue(Node* node){
    Node* temp = node;
    while((temp->left)!=NULL){
            temp = temp->left;
        }
    return temp->data;
}

int main()  
{  
Node* root = NULL;  
root = insert(root, 4);  
insert(root, 2);  
insert(root, 1);  
insert(root, 3);  
insert(root, 6);  
insert(root, 5);  
  
cout << "\n Minimum value in BST is " << minValue(root);  

return 0;  
}  