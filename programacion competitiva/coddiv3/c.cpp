#include <bits/stdc++.h>
using namespace std;

long long int solve(long long int n){
    long long int sum=0;
    while(n!=1){
        sum+=n;
        n=n/2;
    }
    return sum+1;
}

int main(){
    long long int test=0;
    long long int n=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}

