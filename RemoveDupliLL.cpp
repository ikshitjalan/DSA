//Eliminate duplicates from a sorted linked list
#include <iostream>
using namespace std;
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};


node* takeinput(){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cout<<"Enter the data"<<endl;
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* eliminate_duplicate(node* head)
{
    //write your code here
    if(head==NULL){
        return head;
    }
    

    node* temp1 = head;
   
    while(temp1!=NULL){
        if(temp1->next){
            if((temp1->data)==((temp1->next)->data)){
            node* temp2 = temp1;
            while((temp1->next!=NULL)&&(temp1->data)==((temp1->next)->data)){
                
                temp1 = temp1->next;
       
            }
            
            if(temp1->next!=NULL){
                node* a = temp2->next;
                temp2->next = temp1->next;
                delete a;
            }else{
                node* a = temp2->next;
                temp2->next = NULL;
                delete a;
                return head;
            }
           
                          
        }

        }
        
         temp1 = temp1->next;
       
    }
    return head;
}


int main(){
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

