#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* new_Node(int new_data){
    Node* node = new Node();
    node->data = new_data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(Node* temp){
    if(!temp){
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

void insert(Node* temp,int new_data){
    queue<Node*>q;
    q.push(temp);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if (!temp->left){
            temp->left=new_Node(new_data);
            break;
        }
        else{
            q.push(temp->left);
        }    
        if (!temp->right){
            temp->right=new_Node(new_data);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
}

int main(){
    Node* root = new_Node(10); 
    root->left = new_Node(11); 
    root->left->left = new_Node(7); 
    root->right = new_Node(9); 
    root->right->left = new_Node(15); 
    root->right->right = new_Node(8); 
  
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
  
    int key = 12; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 
  
    return 0; 
}