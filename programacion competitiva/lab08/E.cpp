#include <bits/stdc++.h>
using namespace std;


void solve(long long int n,long long k){
    long long int temp= pow(k+1/2,2);
    if((n-k)%2==0 && temp<=n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}

int main(){
    long long int test=0;
    long long int n=0,k=0;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>n>>k;
        solve(n,k);
    }
    return 0;
}

