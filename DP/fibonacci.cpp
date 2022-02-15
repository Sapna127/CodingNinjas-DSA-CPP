//nth fibonacii num
#include<iostream>
using namespace std;

//brute force 
//O(2^n)
int fibo(int n){
    if(n<=1) return 1;
    return fibo(n-1) + fibo(n-2);
}

//memoization (top - down)
//O(n)
int fibo_helper(int n, int *ans){
    if(n<=1) return n;
    if(ans[n] != n){
        return ans[n];
    }
    int a = fibo_helper(n-1,ans);
    int b = fibo_helper(n-2,ans);
    ans[n] = a+b;
    return ans[n];
}
int fibo_1(int n){
    int *ans=new int[n+1];
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }
    return fibo_helper(n,ans);
}

//dynamic programming (bottom - up)
//O(n)
int fibo_3(int n){
    int *ans = new int[n+1];
    for(int i=0 ; i<n ; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

int main(){
  int n;
  cin>>n;
  cout<<fibo_1(n)<<endl;
return 0;
}