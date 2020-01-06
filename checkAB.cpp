#include<iostream>
using namespace std;

bool checkAB(char input[]) {
	// Write your code here
    if(input[0]=='\0'){
        return true;
    }
    int count;
    if(input[0]=='a'){
        count=0;
        if(input[1]=='a'){
            count++;
            return checkAB(input+2);
        }else if((input[1]=='b')){
            count++;
            if(input[2]=='b'&&(input[3]=='a'||input[3]=='\0')){
                
                return checkAB(input+4);
            }else{
                return false;
            }
        }else if(input[1]=='\0'){
            return true;
        }else{
            return false;
        }   
    }else if(1<=count&&input[0]=='b'){
        if(input[1]=='b'&&(input[2]=='a'||input[2]=='\0'))
        return checkAB(input+3);
    }else{
        return false;
    }
    

}


int main(){
    char check[] = "abbabba";
    bool ans = checkAB(check);
    cout << ans;
    return 0;
}




