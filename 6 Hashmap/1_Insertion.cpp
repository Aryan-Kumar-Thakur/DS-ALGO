#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //creation
      map<string,int> m;

    //Intertion
    //1st method
    pair<string,int> p=make_pair("Aryan",5);
    m.insert(p);
    //2nd method
    pair<string,int> pair2("Thakur",2);
    m.insert(pair2);
    //3rd method
    m["mera"]=1;
    //updation
    m["mera"]=2;

    //searching
    cout<<m["mera"]<<endl;
    cout<<m.at("Aryan")<<endl;
   // cout<<endl<<endl;
    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;
    cout<<endl<<endl;
    //size
    cout<<m.size()<<endl;
    cout<<endl<<endl;
    cout<<m.count("bro")<<endl;
    cout<<m.count("Aryan")<<endl;

    //erase
    //m.erase("Thakur");
    cout<<m.size()<<endl;

    //iterator
    map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}