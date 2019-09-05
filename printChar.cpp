#include<iostream>
using namespace std;

void print(char* c){
int i=0;
    while(c[i]!='\0'){
        cout<<c[i];
        i++;
    }
    cout<<" ";
}

int main(){
    char c[20] = "Hello";
    print(c);
    return 0;
}