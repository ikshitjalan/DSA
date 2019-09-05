#include<iostream>
using namespace std;

int main() 
{ 
int size = 4; 

/* Stored in heap segment like other dynamically allocated things */
char *str = (char *)malloc(sizeof(char)*size); 
*(str+0) = 'G';
cout<< *(str+0)<<endl;
*(str+1) = 'f'; 
*(str+2) = 'G';	 
*(str+3) = '\0'; 
*(str+1) = 'n'; /* No problem: String is now GnG */
cout<<str<<endl;
return 0; 
}	 
