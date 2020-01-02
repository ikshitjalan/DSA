#include<iostream>
#include <string.h>
using namespace std;
int getCodes(string input, string output[1000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string output1[1000];
    string output2[1000];

    int ans2 = getCodes(input.substr(1),output2);
    int check2 = input[0]-'0';
    for(int i=0;i<ans2;i++){
        int a = 'a';
            output2[i] = char(a+check2-1)+output2[i];
            // cout<<output2[i]<<endl;
        }
    
        for(int j=0;j<ans2;j++){
            output[j] = output2[j];
        }
    int one = input[1]-'0';
    cout<<"one"<<one<<endl;
    int zero = input[0]-'0';
    cout<<"zero"<<zero<<endl;
    int check = (zero)*10+(one);
    if((0<=one&&one<=10)&&(0<=zero&&zero<=10)&&(10<=check&&check<=26)){
        
    
    cout<<"check1"<<check<<endl;
    
    if((10<=check<=26)&&(input.size()>=2)){
         cout<<"check2"<<check<<endl;
        int ans1 = getCodes(input.substr(2),output1);
        for(int i=0;i<ans1;i++){
             int a = 'a';
            output1[i] = char(a+check-1)+output1[i];
            // cout<<output2[i]<<endl;
        } 
        for(int i=0;i<ans1;i++){
        output[ans2+i] = output1[i];
           
            
    }
        return ans1+ ans2;
    }
    }

   return ans2;
   
    
}


int main(){
    string input = "35411";
    string output[1000];
    int count = getCodes(input, output);
    for(int i = 0; i < count ; i++)
        cout << output[i] << endl;
    return 0;
}
