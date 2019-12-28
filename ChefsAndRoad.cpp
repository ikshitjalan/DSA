#include<iostream>
using namespace std;
int coun = 0;
int count(int ,int[][2],int ,int,int);
int main(){
    int n,m,paths,I,f;
    cin>>n;
    cin>>m;
    cin>>I;
    cin>>f;
    int a[m][2];
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<2;j++){
            cin>>a[i][j];
        }   
    }

    paths = count(I,a,m,f,0);
    cout<<paths;
    return 0;
}

int count(int I,int a[][2],int m,int f,int c){
    
    
    if((a[c][1]==f)&&(a[c][0]==I)){
        coun = coun+1;
        return coun;
    }
    for(int i=0;i<m;i++){
        if(a[i][0]==I){
            count(a[i][1],a,m,f,c+1);
        }else if(i==m-1){
            
            return 0;
        }
    }

}