#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size=0;
    void insert(int value){
        size=size+1;
        arr[size]=value;
        int index=size;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void deletion(){
        if(size==0){
            cout<<"Nothing to delete "<<endl;
            return;
        }
        //step 1: put last element at first position
        arr[1]=arr[size];
        //step 2: remove last element
        size--;
        //step 3: correct the heap with the help of heap order property
        int index=1;
        while(index<size){
            int leftindex=2*index;
            int rightindex=2*index+1;
            if(leftindex<size && arr[index]<arr[leftindex]){
                swap(arr[index],arr[leftindex]);
                index=leftindex;
            }
            else if(rightindex<size && arr[index]<arr[rightindex]){
                swap(arr[index],arr[rightindex]);
                index=rightindex;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout<<"Now delete it "<<endl;
    h.deletion();
    h.print();
    return 0;
}