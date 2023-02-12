#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(7);
    q.push(8);
    q.push(12);
    cout<<"size of queue is "<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<"size of queue is "<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<"size of queue is "<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<"size of queue is "<<q.size()<<endl;
    cout<<q.front()<<endl;

    cout<<"Is queue empty "<<q.empty()<<endl;
    return 0;
}