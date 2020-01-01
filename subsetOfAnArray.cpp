#include<iostream>
using namespace std;
// RIGHT PROGRAM
int subset(int input[],int n,int start,int end,int output[][20]){
    if(n==0){
        output[0][0]=0;
        return 1;
    }
    
    int ans = subset(input,n-1,start,end-1,output);
    for(int i=0;i<ans;i++){
        int size = output[i][0];
        for(int j=0;j<=size;j++){
            output[ans+i][j] = output[i][j]; 
        }
        output[ans+i][size+1] = input[end]; 
        output[ans+i][0] = output[ans+i][0]+1;
        
    }
      return 2*ans;
}
int subset(int input[], int n, int output[][20]) {
    // Write your code here
    int start=0;
    int end=n-1;
    int ans = subset(input,n,start,end,output);
    return ans;
    
}


int main(){
    int input[] = {19,3,9};
    int n = 3;
    int output[400][20];
    int ans = subset(input,n,output);
    cout<<ans<<endl;
    return 0;
}