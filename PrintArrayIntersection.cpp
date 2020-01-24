#include<iostream>
using namespace std;

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    if(size1==0){
       
        return;
    }
    int i=0;
while((input1[0]!=input2[i])&&(i<=size2-1))
{    
    i++;
}
    if(i<=size2-1){
        cout<<input1[0]<<endl;
    }
    
    intersection(input1+1,input2,size1-1,size2);

}



int main() {

	int size1,size2;

	size1=6;
    int input1[] ={2,6,8,5,4,3};
	
	

	size2=4;
    int input2[] = {2,3,4,7};
	
	

	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}

