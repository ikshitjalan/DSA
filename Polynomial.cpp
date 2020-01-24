#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial{
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    
    //Default Constructor
    Polynomial(){
        capacity = 5;
        degCoeff = new int[capacity];
        for(int i=0;i<capacity;i++){
            degCoeff[i] =0;
        }
    }
    //Copy Constructor
     Polynomial(Polynomial const &p2){
        this->capacity = p2.capacity;
        this->degCoeff = new int[capacity];
        
        for(int i=0;i<this->capacity;i++){
            this->degCoeff[i] = p2.degCoeff[i];
        }
         
    }
    
    //Copy Assignment operator
    void operator=(Polynomial const &p2){
        this->capacity = p2.capacity;
        this->degCoeff = new int[p2.capacity];
        
        for(int i=0;i<this->capacity;i++){
            this->degCoeff[i] = p2.degCoeff[i];
        }
        
    }
    //setCoefficient
    void setCoefficient(int degree,int coefficient){
        if(degree<(this->capacity)){
            this->degCoeff[degree] = coefficient;
        }else if(degree>=(this->capacity)){
            this->capacity *=2;
            int *degCoeff2 = new int[this->capacity];
            for(int i=0;i<this->capacity;i++){
                degCoeff2[i]=0;
            }
            for(int i=0;i<(this->capacity)/2;i++){
                degCoeff2[i] =this->degCoeff[i]; 
            }
            delete [] degCoeff;
            this->degCoeff = degCoeff2;
            this->degCoeff[degree] = coefficient;
        
            
        }
    }
    Polynomial operator+(Polynomial const &p2){
        Polynomial newP;
        newP.capacity = max(this->capacity,p2.capacity);
        int mini = min(this->capacity,p2.capacity);
        newP.degCoeff = new int[newP.capacity];
        for(int i=0;i<newP.capacity;i++){
            if(i<mini){
            newP.degCoeff[i] = this->degCoeff[i] + p2.degCoeff[i];    
            }else if(p2.capacity>this->capacity){
                newP.degCoeff[i] = p2.degCoeff[i];
            }else if(p2.capacity<this->capacity){
                newP.degCoeff[i] = this->degCoeff[i];
            }
            
        }
        return (newP);
        }
    
    Polynomial operator-(Polynomial const &p2){
        Polynomial newP;
        newP.capacity = max(this->capacity,p2.capacity);
        int mini = min(this->capacity,p2.capacity);
        newP.degCoeff = new int[newP.capacity];
        for(int i=0;i<newP.capacity;i++){
            if(i<mini){
            newP.degCoeff[i] = this->degCoeff[i] - p2.degCoeff[i];    
            }else if(p2.capacity>this->capacity){
                newP.degCoeff[i] = -p2.degCoeff[i];
            }else if(p2.capacity<this->capacity){
                newP.degCoeff[i] = this->degCoeff[i];
            }
        }
        return (newP);
    }
    
    Polynomial operator*(Polynomial const &p2){
    
        Polynomial newP1;
        newP1.capacity =(this->capacity+ p2.capacity);
        for(int i=0;i<newP1.capacity;i++){
            newP1.degCoeff[i] = 0;
        }
        for(int i=0;i<this->capacity;i++){
            for(int j=0;j<p2.capacity;j++){
                 newP1.degCoeff[i+j] =   newP1.degCoeff[i+j] + (this->degCoeff[i])*p2.degCoeff[j];
            }
           
        }
        return newP1;
    }
    
    void print(){
        for(int i=0;i<this->capacity;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
    }
    // Complete the class
    
};




//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cout<<"Number of elemets in poly 1"<<endl;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cout<<"degree"<<i+1<<endl;
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cout<<"coeff"<<i+1<<endl;
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    cout<<"Number of elemets in poly 2"<<endl;
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cout<<"degree2"<<i+1<<endl;
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cout<<"coeff2"<<i+1<<endl;
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    cout<<"your choice"<<endl;
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
