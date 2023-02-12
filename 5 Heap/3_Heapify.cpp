#include<iostream>
using namespace std;

class heap{
    int arr[100];
    int size=0;
};

void heapify(int arr[],int n,int i){
    int largest=i;
    int leftindex=2*i;
    int rightindex=2*i+1;
    if(leftindex<n && arr[leftindex]>arr[largest]){
        largest=leftindex;
    }
    if(rightindex<n && arr[rightindex]>arr[largest]){
        largest=rightindex;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"The heapify array is "<<endl;
    for(int i=1;i<=5;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    return 0;
}