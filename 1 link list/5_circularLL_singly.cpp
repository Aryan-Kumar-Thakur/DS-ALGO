#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"\nThe deleted value is "<<value<<endl;
    }
};

void nodetoinsert(node* &tail,int element,int data){
    //EMpty list
    if(tail==NULL){
         node* temp=new node(data);
         tail=temp;
        temp->next=temp;
    }
    else{
        //assumong lement is present in the list
        node* temp=new node(data);
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deleteat(node* &tail,int value){
    if(tail==NULL){
        cout<<"List is empty, please enter elements "<<endl;
    }
    else{
    node* prev=tail;
    node* curr=prev->next;
    //special case when we have 1 node only
    if(curr==prev){
        tail=NULL;
    }
    //Normal cases
    while(curr->data!=value){
        prev=curr;
        curr=curr->next;
    }
    //If we have to delete 1st node
    if(tail==curr){
        tail=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
}

void print(node* tail){
    node* temp=tail;
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
}

int main(){
    node* tail=NULL;
    print(tail);
    cout<<endl<<endl;
    nodetoinsert(tail,0,3);
    print (tail);
    cout<<"\n\nNow we do insertion "<<endl;
    nodetoinsert(tail,3,5);
    /*nodetoinsert(tail,5,7);
    nodetoinsert(tail,7,9);
    nodetoinsert(tail,5,6);
    nodetoinsert(tail,9,10);
    nodetoinsert(tail,3,4);*/
    print(tail);
    cout<<"\n\nNow we perform deletion"<<endl;
    deleteat(tail,5);
    print(tail);
    return 0;
}