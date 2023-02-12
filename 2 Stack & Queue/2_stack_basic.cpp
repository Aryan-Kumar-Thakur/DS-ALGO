#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
     node* head=NULL;
    void push(int x){
        node* temp=new node();
        temp->data=x;
        temp->next=head;
        head=temp;
    }

    void pop(){
        if(head==NULL){
            cout<<"stack is empty"<<endl;
        }
        else{
            node* temp=head;
            head=head->next;
            delete(temp);
        }
    }

    int peak(){
        if(head==NULL){
            cout<<"stack is empty "<<endl;
            return -1;
        }
        else{
            return head->data;
        }
    }
    bool isempty(){
        if(head==NULL) return 1;
        else{ 
            return 0;
        }
    }

    void print(node* head){
        node* temp;
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
        }
        else{
            temp=head;
            cout<<"Elements are "<<endl;
            while(temp!=NULL){
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

int main(){
    push(33);
    push(22);
    push(44);
    push(55);
    push(66);
    print(head);
    pop();pop();pop();
    print(head);
    cout<<endl<<endl;
    cout<<peak()<<endl<<endl;
    cout<<isempty()<<endl<<endl;
    pop();pop();
    cout<<peak()<<endl;
    cout<<endl<<endl;
    cout<<isempty()<<endl<<endl;
    return 0;
}