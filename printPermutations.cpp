#include<iostream>
#include<string.h>
using namespace std;

void printPermutations(string input,string output){
    
    if(input.empty()){
        for(int j=0;j<output.size();j++){
            cout<<output[j];
            
        }
        cout<<endl;
        return;
    }
    
    int size = input.size();
    for(int i=0;i<size;i++){
        if(i==(size-1)){
           
            printPermutations(input.substr(0,size-1),output+input[i]);
        }else{
            
            printPermutations(input.substr(0,i)+input.substr(i+1),output+input[i]);
        }
    }
}


void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output ="";
    printPermutations(input,output);
}


int main(){
    string input ="abc";
    
    printPermutations(input);
    return 0;
}
