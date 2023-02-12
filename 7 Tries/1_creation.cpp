#include<iostream>
using namespace std;
class trienode{
    public:
    char data;
    trienode* children[26];
    bool isterminal;
    trienode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
        children[i]=NULL;
        }
        isterminal=false;
    }
};

class trie{
    public:
    trienode* root;
    trie(){
        root=new trienode('\0');
    }
    void insertutil(trienode* root,string word){
        //base case
        if(word.size()==0){
            root->isterminal=true;
            return;
        }
        //we assume that we give input in CAPS
        int index=word[0]-'A';
        //create a child
        trienode* child;
        if(root->children[index]!=NULL){
            //word is present
            child=root->children[index];
        }
        else{
            //word is absent
            child=new trienode(word[0]);
            root->children[index]=child;
        }
        //recursive call
        insertutil(child,word.substr(1));
    }
    void insertword(string word){
        //call a function so we perform recursive insertion
        insertutil(root,word);
    }
};

int main(){
    trie* t=new trie();
    t->insertword("ABCD");
    return 0;
}