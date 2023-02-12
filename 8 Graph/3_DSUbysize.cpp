#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class disjoint{
    vector<int> size,parent;
    public:
    disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find_ulparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find_ulparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=find_ulparent(u);
        int ulp_v=find_ulparent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main(){
    disjoint d1(7);
    d1.unionbysize(1,2);
    d1.unionbysize(2,3);
    d1.unionbysize(4,5);
    d1.unionbysize(6,7);
    d1.unionbysize(5,6);
    cout<<"Is 3 and 7 belong to same component ??"<<endl;
    if(d1.find_ulparent(3)==d1.find_ulparent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    d1.unionbysize(3,7);
    cout<<"Is 3 and 7 belong to same component ??"<<endl;
    if(d1.find_ulparent(3)==d1.find_ulparent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    return 0;
}