#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(){
       this->next=NULL;
    }

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertathead(node* &head,int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}

void insertattail(node* &tail,int data){
    node* temp=new node(data);
    tail->next=temp;
    tail=temp;
}

void insertatmiddle(node* &head,node* &tail,int position,int data){
    node* temp=head;
    node* nodetoinsert=new node(data);
    if(position==1){
        insertathead(head,data);
        return;
    }
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(tail,data);
        return;
    }
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

void print(node* &head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node* node1=new node();
    node1->data=5;
    node* head=node1;
    node* tail=node1;
    print(head);
    cout<<endl;
    insertattail(tail,12);
    insertattail(tail,15);
    insertattail(tail,18);
    print(head);

    insertatmiddle(head,tail,3,22);
    cout<<endl;
    print(head);
    cout<<endl<<endl;
    cout<<"head  "<<head->data<<endl;
    cout<<"tail  "<<tail->data<<endl;
    return 0;
}