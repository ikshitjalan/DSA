#include<iostream>
using namespace std;

int main(){
    int* p = (int *)malloc(4*sizeof(int));
    cout<<p<<endl;
    for(int i =0;i<4;i++){
        *(p+i) = i+1;
    }
    for(int i =0;i<4;i++){
        cout<<*(p+i)<<endl; 
    }
    free(p);
    for(int i =0;i<4;i++){
        cout<<endl;
        cout<<*(p+i)<<endl; 
    }
    cout<<p;
    return 0;
}