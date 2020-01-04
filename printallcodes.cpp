#include<iostream>
#include<string.h>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/

    if(input.empty()){
        return 1;
    }

    int ans = returnPermutations(input.substr(1),output);
  
   
    string output2[10000];
    int k=0;
    for(int j=0;j<ans;j++){
        string str1 = output[j];
        int size1 = output[j].size();
        for(int i=0;i<=size1;i++){
            string str2;
            if(i==0){
                str2 = input[0]+str1.substr(i);
            }else if(i==size1){
                str2 = str1.substr(0,i)+input[0];                  
            }else if((1<=i)&&(i<=size1)){
                str2 = str1.substr(0,i)+input[0]+str1.substr(i);
            }
             output2[k] = str2;
                k++;
            }
          
            
            
        }
        cout<<"K"<<k<<endl;
          for(int i=0;i<k;i++){
                output[i] = output2[i];
     
            }
    
    return k;
}

int main(){
    string input = "abcd";
    
    string output[1000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count ; i++){
        cout << output[i] << endl;
    }
    return 0;
}
