#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int main(){
unordered_map<string,int> ourmap;
ourmap["abc"]=1;
ourmap["abc1"]=2;
ourmap["abc2"]=3;
ourmap["abc3"] = 4;
//iteratores on map
unordered_map<string,int> :: iterator it = ourmap.begin();
while(it!=ourmap.end()){
    cout<<"key : "<<it->first <<"   Value: "<<it->second<<endl;
    it++;
}

//find
unordered_map<string,int> :: iterator it2 = ourmap.find("abc");
ourmap.erase(it2,it2 + 4);
//iterators in vector
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
vector<int> :: iterator it1=v.begin();
while(it1 != v.end()){
    cout<< *it1<<endl;
    it++;
}

return 0;
}