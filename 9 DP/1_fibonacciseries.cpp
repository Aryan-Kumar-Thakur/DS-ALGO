#include<iostream>
using namespace std;

int fibonacci(int n,int dp[]){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

int main(){
    int n;
    cout<<"Enter the number of term"<<endl;
    cin>>n;
    int dp[n+1];
    //Memoization

    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<fibonacci(n,dp)<<endl;
    

    //Tabulation

    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;

    //space optimization

    int prev2=0,prev=1,curr;
    for(int i=2;i<=n;i++){
        curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    cout<<prev<<endl;
    return 0;
}