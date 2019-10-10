#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* right;
    Node* left;
}Node;

Node* newNode(int new_data){
    Node* new_Node= new Node();
    new_Node->data = new_data;
    new_Node->left = NULL;
    new_Node->right = NULL;
    return new_Node;
}

int main(){
      /*create root*/
   Node *root = newNode(1);   
  /* following is the tree after above statement  
  
        1 
      /   \ 
     NULL  NULL   
  */
    
  
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  /* 2 and 3 become left and right children of 1 
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  root->left->left  = newNode(4); 
  /* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
  
  return 0; 

}
