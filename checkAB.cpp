#include<iostream>
using namespace std;

bool checkAB(char input[],int start,int end){
    if((start+1)=='\0'||start=='\0'){
       return true; 
    }
    
    
    if(input[start]=='a'){
        if(input[start+1]=='a'||input[start+1]=='b'||input[start+1]=='\0'){
            cout<<"here1"<<endl;
            return checkAB(input,start+2,end);;

            }else{
            return false;
        }
    }
    else if(input[start]=='b'||input[start-1]=='b'){
        if(input[start+1]=='a'||input[start+1]=='\0'){
            cout<<"here1"<<endl;
            return checkAB(input,start+2,end);;
        }else{
            return false;
        }
    }
    else if(input[start]=='b'||input[start-1]=='a'){
        if(input[start+1]=='b'){
            cout<<"here1"<<endl;
            return checkAB(input,start+2,end);;
        }else{
            return false;
        }
    }else{
        return false;
    }
     
}

bool checkAB(char input[]) {
	// Write your code here
    int start = 0;
    int i=0;
    while(input[i]=='\0'){
        i++;
    }
    checkAB(input,start,i-1);
}

int main(){
    char check[] = "abbbabaaa";
    bool ans = checkAB(check);
    cout << ans;
    return 0;
}




