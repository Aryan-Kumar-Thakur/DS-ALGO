#include<iostream>
using namespace std;

class node{
    public:
     int data;
     node* left;
     node* right;
     node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
     }
};

node* buildtree(node* root){
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left part of the "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right part of the "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
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

int main(){
    node* root=NULL;
    root=buildtree(root);
    cout<<"Inorder traversal is "<<endl;
    inordertraverse(root);
    cout<<"Preorder traversal is "<<endl;
    preordertraverse(root);
    cout<<"Postorder traversal is "<<endl;
    postordertraverse(root);
    
    return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 