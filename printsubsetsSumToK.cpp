#include<iostream>
using namespace std;

void printSubsetSumToK(int input[],int start,int end,int size,int output[],int size2,int k){
    if(size==0){
        if(k==0){
            for(int l=0;l<size2;l++){
            cout<<output[l]<<" ";
        }
        cout<<endl;
        return;
        }else{
            return;
        }
        
    }
   
   
   
    printSubsetSumToK(input,start+1,end,size-1,output,size2,k);
    int output2[200];
    
    for(int i=size2-1;i>=0;i--){
        output2[i] = output[i];
    }
    output2[size2] = input[start];
    size2 = size2+1;
    
      printSubsetSumToK(input,start+1,end,size-1,output2,size2,k-input[start]);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int size2 = 0;
    int output[50];
    int start=0;
    int end = size-1;
    printSubsetSumToK(input,start,end,size,output,size2,k); 
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
