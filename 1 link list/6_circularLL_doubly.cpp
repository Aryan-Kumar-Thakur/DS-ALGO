#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL||this->prev!=NULL){
            delete next;
            this->next=NULL;
            this->prev=NULL;
        }
        cout<<"\nThe deleted value is "<<value<<endl;
    }
};

void insertatnode(node* &tail,int value,int data){
    if(tail==NULL){
        node* temp=new node(data);
        tail=temp;
        tail->next=temp;
        tail->prev=temp;
    }
    else{
        node* temp=new node(data);
        node* curr=tail;
        while(curr->data!=value){
            curr=curr->next;
        }
        if(curr==tail){
            curr->prev=temp;
        }
        temp->next=curr->next;
        curr->next=temp;
        temp->prev=curr;
    }
}

void deleteat(node* &tail,int value){
    if(tail==NULL){
        cout<<"List is empty,please enter element "<<endl;
    }
    else{
        node* prev=tail;
        node* curr=prev->next;
        if(curr==prev){
            tail=NULL;
        }
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        if(curr==tail){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next->prev=prev;
        curr->next=NULL;
        curr->prev=NULL;
        delete curr;
    }
}

void print(node* tail){
    if(tail==NULL){
        cout<<"The list is empty "<<endl;
        return;
    }
    node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
}

int main(){
    node* tail=NULL;
    print(tail);
    insertatnode(tail,0,3);
    print(tail);
    cout<<"\nNow we inserting data in it "<<endl;
    insertatnode(tail,3,5);
    insertatnode(tail,5,7);
    insertatnode(tail,7,9);
    print(tail);
    cout<<"\nNow we perform deletion "<<endl;
    deleteat(tail,3);
    print(tail);
    return 0;
}