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

void inordertraverse(node* root){
    if(root==NULL){
        return;
    }
    inordertraverse(root->left);
    cout<<root->data<<" ";
    inordertraverse(root->right);
}

void preordertraverse(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preordertraverse(root->left);
    preordertraverse(root->right);
}

void postordertraverse(node* root){
    if(root==NULL){
        return;
    }
    postordertraverse(root->left);
    postordertraverse(root->right);
    cout<<root->data<<" ";
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

int minval(node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

node* findanddeletenode(node* root,int value){
    if(root==NULL){
        return root;
    }
    if(root->data==value){
         if(root->left==NULL && root->right==NULL){
        delete(root);
        return NULL;
    }
    if(root->left!=NULL && root->right==NULL){
        node* temp=root->left;
        delete(root);
        return temp;
    }
    if(root->left==NULL && root->right!=NULL){
        node* temp=root->right;
        delete(root);
        return temp;
    }
    if(root->left!=NULL && root->right!=NULL){
        int mini=minval(root->right);
        root->data=mini;
        root->right=findanddeletenode(root->right,mini);
        return root;
    }
    }
    else if(root->data>value){
        root->left= findanddeletenode(root->left,value);
        return root;
    }
    else{
        root->right=findanddeletenode(root->right,value);
        return root;
    }
}

int main(){
    node* root=NULL;
    cout<<"Enter the data to create BST "<<endl;
    takeinput(root);
    cout<<"Printing the bst in level order "<<endl;
    levelordertransversal(root);
    cout<<endl<<"Printing the bst in Inorder"<<endl;
    inordertraverse(root);
    cout<<endl<<"Printing the bst in preorder"<<endl;
    preordertraverse(root);
    cout<<endl<<"Printing the bst in postorder"<<endl;
    postordertraverse(root);
    int value;
    cout<<endl<<endl;
    cout<<"Enter the data to be deleted"<<endl;
    cin>>value;
    cout<<endl<<endl;
    root=findanddeletenode(root,value);
    levelordertransversal(root);
    cout<<endl<<"Printing the bst in Inorder"<<endl;
    inordertraverse(root);
    cout<<endl<<"Printing the bst in preorder"<<endl;
    preordertraverse(root);
    cout<<endl<<"Printing the bst in postorder"<<endl;
    postordertraverse(root);
    return 0;
}

//50 20 70 10 30 90 110 -1
