#include<iostream>
using namespace std;

void merge(int input[],int start,int mid,int end){
    int i=0;
    int j=0;
    int k=start;
    int size_a = mid-start+1;
    int size_b = end-mid;
    int a[size_a];
    int b[size_b];
   
    for(i=0;i<size_a;i++){
        a[i] = input[start+i];
      
    }
  
    
    for(j=0;j<size_b;j++){
        b[j] = input[mid+1+j];
        cout<<b[j]<<" ";
    }
    cout<<endl;
    cout<<"sizes: "<<size_a<<" "<<size_b<<endl;
    i=0; j=0;
    while((i<size_a)&&(j<size_b)){
        if(a[i]<=b[j]){
            cout<<"hi";
            input[k]=a[i];
            i++;
            
        }else{
            cout<<"bi";
            input[k]=b[j];
            j++;
           
        }
        k++;
    }
    while(i<size_a){
        input[k]=a[i];
        i++;
        k++;
    }
    
    while(j<size_b){
        input[k]=b[j];        j++;
        k++;
    }
}
//6
//2 6 8 5 4 3

void mergeSort(int input[],int start,int end){
    if(start<end){
    int mid = (start+end)/2;
    mergeSort(input,start,mid);
    mergeSort(input,mid+1,end);
    merge(input,start,mid,end);
    }
    
}


void mergeSort(int input[], int size){
    // Write your code here
    int len = size;
    mergeSort(input,0,len-1);
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}