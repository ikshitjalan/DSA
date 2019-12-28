#include<iostream>
using namespace std;
void swap(int *a , int *b){
    int temp = *a;
    *a=*b;
    *b = temp;
    
}

int partition(int input[],int start,int end){
    int pivot = start;
    int len = end-start+1;
    int count = 0;
    int i=1;
    while(i<len){
        if(input[i]<=input[pivot]){
            count++;
        }
        i++;
    }
    
    swap(&input[start],&input[start+count]);
    pivot = start+count;
    
    
    int j=start;
    int k=end;
    while((pivot>=j)&&(k>=pivot)){
    if((input[j]<=input[pivot])){
            
        j++;
    }else if((input[pivot]<input[k])){
        
        k--;
        
    }else{
        swap(&input[j],&input[k]);
        k--;
        j++;
    }
    }
    
    return pivot;
    
}

void quickSort(int input[],int start,int end){
    if(start>=end){
        return;
    }
    
    int pivot = partition(input,start,end);
    
    quickSort(input,start,pivot-1);
    quickSort(input,pivot+1,end);
    
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quickSort(input,0,size-1);
}


void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr,  n); 
    printf("Sorted array: n     "); 
    printArray(arr, n); 
    return 0;
}