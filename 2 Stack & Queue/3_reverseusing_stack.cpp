#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main(){
    stack<int> s;
    string a="Aryan";
    for(int i=0;i<a.size();i++){
        s.push(a[i]);
    }
    string ans="";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"answer is "<<ans<<endl;
    return 0;
}