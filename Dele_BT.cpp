#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* right;
    Node* left; 
}

Node* newNode(int newData){
    Node* new_Node = new Node();
    new_Node->data = newData;
    new_Node->right  = NULL;
    new_Node->left  = NULL;
    return new_Node;
}

void deleDeepest(Node* root,Node* d_node){
    queue<Node*>q;
    q.push(root);
    Node* temp ;
    while(!q.empty()){
        
        temp = q.front();
        q.pop()
        if(temp==d_node){
            delete(temp);
            return;
        }
        if(temp->right){
            if(temp->right==d_node){
                delete(temp->right);
                return;
            }
            else{
                q.push(temp->right);
            }
            
        }
        if(temp->left){
            if(temp->left == d_node){
                delete(temp->left);
                return;
            }
            else{
                q.push(temp->left);
            }
        }

    }
    }

Node*  deletion(Node* root ,int key){
    
    while()
}