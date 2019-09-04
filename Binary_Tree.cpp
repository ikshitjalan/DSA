#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* new_Node(int new_data){
    Node* node = new Node();
    node-> data = new_data;
    node-> left = NULL;
    node-> right = NULL;
    return node;
}

int main(){
    Node* root = new_Node(9);
    root->left = new_Node(10);
    root->right = new_Node(8);
    cout<<root->data;
    return 0;
}