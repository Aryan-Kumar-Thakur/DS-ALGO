#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class disjoint{
    vector<int> rank,parent;
    public:
    disjoint(int n){
        rank.resize(n+1,0);
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
    void unionbyrank(int u,int v){
        int ulp_u=find_ulparent(u);
        int ulp_v=find_ulparent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main(){
    disjoint d1(7);
    d1.unionbyrank(1,2);
    d1.unionbyrank(2,3);
    d1.unionbyrank(4,5);
    d1.unionbyrank(6,7);
    d1.unionbyrank(5,6);
    cout<<"Is 3 and 7 belong to same component ??"<<endl;
    if(d1.find_ulparent(3)==d1.find_ulparent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    d1.unionbyrank(3,7);
    cout<<"Is 3 and 7 belong to same component ??"<<endl;
    if(d1.find_ulparent(3)==d1.find_ulparent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    return 0;
}