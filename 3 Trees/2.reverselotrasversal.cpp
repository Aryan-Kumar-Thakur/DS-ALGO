#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node *buildtree(node *root){
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left= buildtree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right= buildtree(root->right);
    return root;
}
void reverse(node* &root){
    queue<node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        ans.push_back(temp->data);
        if(root->right){
            q.push(root->right);
        }
        if(root->left){
            q.push(root->left);
        }
        q.pop();
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}
int main(){
    node *root=NULL;
    root=buildtree(root);
    //print(root);
    cout<<"printing the level order tranversal output "<<endl;
    reverse(root);
    return 0;
}