#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    //for 1 based indexing
    //using 2 D matrix
    /*int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }*/
    //Using 1 D list or array
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}