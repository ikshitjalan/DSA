#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class BinaryTree{
    public:
    T data;
    vector<BinaryTree<T>*> children;

    
    BinaryTree(data){
        this->data =data;
    } 
};
template <typename T>
void takeinput(){
    T data;
    cout<<"Enter root data"<<endl;
    cin>>data;
    BinaryTree<T>* root = new BinaryTree<T>(data);
    queue<BinaryTree<T>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTree<T>* node = q.front();
        q.pop();
        int num;
        cout<<"Enter the number of childs of"<<node->data<<endl;
        cin>>num;
        for(int i=0;i<num;i++){
            cout<<"Enter the "<<i<<"th child of "<<node<<endl;
            T child;
            cin>>child;
            BinaryTree<T>* child = new BinaryTree<T>(child);
            node->children.push_back(child);
            q.push(child);
        }
    }
    return root;

}
