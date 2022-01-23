#include<iostream>
#include<queue>
using namespace std;
int main(){
//min heap 
priority_queue<int,vector<int>,greater<int>> pq;
//max heap
 //priority_queue<int> pq;
 pq.push(18);
 pq.push(2);
 pq.push(43);
 pq.push(33);
 cout<<"size: "<<pq.size()<<endl;
cout<<"Top: "<<pq.top()<<endl;
while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop();
}
return 0;
}