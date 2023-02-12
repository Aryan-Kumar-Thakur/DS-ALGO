#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
   /*node(){
         this->left=NULL;
        this->right=NULL;
    }*/
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void levelordertransversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

node* creation(node* root,int data){
    /*cout<<"Enter the data to be inserted "<<endl;
    int data;cin>>data;*/
    if(root==NULL){
        root=new node(data);
        return root;
    }
    //node* node1=new node(data);
    if(data >root->data){
        root->right=creation(root->right,data);
    }
    else{
        root->left=creation(root->left,data);
    }
    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=creation(root,data);
        cin>>data;
    }
}

int main(){
    node* root=NULL;
    cout<<"Enter the data to create BST "<<endl;
    takeinput(root);
    cout<<"Printing the bst in level order "<<endl;
    levelordertransversal(root);
    return 0;
}

//10 8 21 7 27 5 4 3 -1
