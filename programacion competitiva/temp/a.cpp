#include <bits/stdc++.h>
using namespace std;

void solve(long long int n){
    long long int count=0;
    long long int a=0,b=0;
    for(long long int i=0;i<n;i++){
        cin>>a>>b;
        if(a>b){
            count++;
        }
    }
    cout<<count<<endl;
}

int main(){
    long long int test=0;
    long long int n=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        cin>>n;
        solve(n);
    }
    return 0;
}

