#include <iostream>
#include <queue>

using namespace std;

typedef struct  Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* newNode(int new_data){
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
    cout<<" "<<temp->data;
    inorder(temp->right);

    
    }

void DeleteDeep(Node* root,Node* DNode){
    if(root==DNode){
        return ;
    }

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp =q.front();
        q.pop();
        if(temp==DNode){
            temp =NULL;
            delete(DNode);
            return ;
        }
        if(temp->left){
            if(temp->left==DNode){
                temp->left = NULL;
                delete(DNode);
                return;
            }
        }
        if(temp->right){
            if(temp->right==DNode){
                temp->right = NULL;
                delete(DNode);
                return;
            }
        } 
    }
}

Node* Delete(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL){
        if(root->data == key){
            root =NULL;
            return root;
        }
    }
    Node* temp;
    Node* key_Node = NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if((temp->data)==key){
            key_Node = temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    if(key_Node!=NULL){
        int x = temp->data;
        DeleteDeep(root,temp);
        key_Node->data = x;
    }
    return root;
}
int main(){
    Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = Delete(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
  
    return 0; 
}