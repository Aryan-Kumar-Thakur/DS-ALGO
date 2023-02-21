//Printing the largest common subsequence between two strings
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int ind1,int ind2,string str1,string str2,vector<vector<int>> &dp){
    if(ind1==0 || ind2==0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(str1[ind1-1]==str2[ind2-1]){
        return dp[ind1][ind2] = 1+solve(ind1-1,ind2-1,str1,str2,dp);
    }
    return dp[ind1][ind2] = max(solve(ind1-1,ind2,str1,str2,dp),solve(ind1,ind2-1,str1,str2,dp));
}

void print_lcs(int len,vector<vector<int>> &dp,string str1,string str2){
    int n1=str1.size();
    int n2=str2.size();
    string ans="";
    for(int i=0;i<len;i++){
        ans+='$';
    }
    int ansind=len-1;
    int ind1=n1,ind2=n2;
    while(ind1>0 && ind2>0){
        if(str1[ind1-1]==str2[ind2-1]){
            ans[ansind]=str1[ind1-1];
            ind1--;
            ind2--;
            ansind--;
        }
        else if(dp[ind1-1][ind2]>dp[ind1][ind2-1]){
            ind1--;
        }
        else{
            ind2--;
        }
    }
    for(int i=0;i<len;i++){
        cout<<ans[i];
    }
}

void findlen_oflcs(string str1,string str2){
    int n1=str1.size();
    int n2=str2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
    int len_oflcs=solve(n1,n2,str1,str2,dp);
    cout<<"The length of longest common subsequence is :- "<<len_oflcs<<endl;
    //Now call the print LCS function
    cout<<"The longest common subsequence of these string are :- ";
    print_lcs(len_oflcs,dp,str1,str2);
    cout<<endl;
}

int main(){
    string str1="adebc";
    string str2="dcadb";
    //Expected output :- adb
    findlen_oflcs(str1,str2);
    return 0;
}