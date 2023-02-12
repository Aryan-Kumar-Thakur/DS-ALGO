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
        if(this->next!=NULL || this->prev!=NULL){
            delete next;
            this->next=NULL;
            this->prev=NULL;
        }
        cout<<"\nThe deleted value is "<<value<<endl;
    }
};

void insertathead(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=temp;
        tail=temp;
    }
    else{
    node* temp=new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertattail(node* &tail,node* &head,int data){
    node* temp=new node(data);
    if(tail==NULL){
        node* temp=new node(data);
        tail=temp;
        head=temp;
    }
    else{
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void insertatposition(node* &head,node* &tail,int position,int data){
    if(position==1){
        insertathead(head,tail,data);
        return;
    }
    node* temp=head;
    node* old=NULL;
    node* insertingdata=new node(data);
    int cnt=1;
    while(cnt<position){
        old=temp;
        temp=temp->next;
        cnt++;
    }
    if(old->next==NULL){
        insertattail(tail,head,data);
        return;
    }
    insertingdata->next=old->next;
    old->next=insertingdata;
    insertingdata->prev=old;
}

void deleteat(node* &head,node*&tail,int position){
    node* temp=head;
    if(position==1){
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* old=NULL;
        int cnt=1;
        while(cnt<position){
            old=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            tail=old;
        }
        old->next=curr->next;
        curr->prev=NULL;
        curr->next=NULL;
        delete curr;
    }
}

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void printl(node* &tail){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    print(head);
    cout<<"\nNow we insert at head"<<endl;
    insertathead(head,tail,22);
    insertathead(head,tail,50);
    insertathead(head,tail,40);
    print(head);
    cout<<"\n\nNow we insert at position"<<endl;
    insertatposition(head,tail,3,30);
    print(head);
    cout<<endl<<endl;
    cout<<"Now we do deletion"<<endl;
    deleteat(head,tail,5);
    cout<<endl;
    print(head);
    cout<<"\nHead is "<<head->data<<endl;
    cout<<"\nTail is "<<tail->data<<endl;
   /* cout<<togetlength(head)<<endl;
    node* node2=new node(10);
    node* tail=node2;
    printl(tail);
    cout<<"\n\nNow we insert at tail"<<endl;
    insertattail(tail,head,22);
    insertattail(tail,head,50);
    insertattail(tail,head,40);
    tail=node2;
    printl(tail);*/

    return 0;
}