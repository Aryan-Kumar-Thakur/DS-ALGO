// Implementation of stack using Array

#include<iostream>
using namespace std;

class stack{
    public:

    int top;
    int* arr;
    int size;
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }
    int peak(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty(){
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main(){
    stack st(5);
    st.push(22);
    st.push(44);
    st.push(55);
    st.push(66);
    cout<<"The peak is  "<<st.peak()<<endl;
    st.pop();
    cout<<"The peak is  "<<st.peak()<<endl;
    st.pop();
    cout<<"The peak is  "<<st.peak()<<endl;
    if(st.isempty()){
        cout<<"Stack is empty "<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}