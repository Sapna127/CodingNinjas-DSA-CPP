#include<iostream>
#include<cmath>
using namespace std;
int balancedBTs(int h){
    if(h<=1) return 1;
    //with the help of modulus we can stop our value from getting out of int range
    int mod = (int)(pow(10,9))+7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    int temp = (int)(((long)(x)*x) %mod);
    int temp1 = (int)((2*(long)(x)*y)%mod);
    int ans = (temp+temp1)%mod;
  //  int ans = (x*x + 2*x*y)%mod;
    return ans;
}
int main(){
int h;
cin>>h;
cout << balancedBTs(h)<<endl;
return 0;
}