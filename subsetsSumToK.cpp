#include<iostream>
using namespace std;




int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
        if(n==0){
        if(k==0){
            output[0][0] = 0;
            return 1;
        }else{
            return 0;
             }
        
    }
int output1[400][50];
int output2[400][50];
    int ans1 = subsetSumToK(input+1,n-1,output2,k);
    
    int ans = subsetSumToK(input+1,n-1,output1,k-input[0]);
    for(int j=0;j<ans1;j++){
        int size2 = output2[j][0];
        for(int l=0;l<=size2;l++){
            output[j][l] = output2[j][l];
            
        }        
     }
    
    for(int j=0;j<ans;j++){
        int size1 = output1[j][0];
        output[j+ans1][0] = output1[j][0]+1;
            
    for(int l=size1;l>=1;l--){
        output[j+ans1][l+1] = output1[j][l];
        }
        output[j+ans1][1] = input[0];
        
    }
    return ans+ans1;
}

int main(){
    int input[] = {17, 18, 6, 11, 2, 4 };
    int n=6;
    int k=6;
    int output[400][50];
    int ans3 = subsetSumToK(input,n,output,k);
    for(int i=0;i<ans3;i++){
    int size = output[i][0];
    for(int j=0;j<=size;j++){
        cout<<output[i][j]<<endl;
    }
        cout<<" "<<endl;
    }
    cout<<ans3<<endl;
    return 0;
}