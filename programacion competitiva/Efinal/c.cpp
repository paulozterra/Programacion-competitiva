#include <bits/stdc++.h>
using namespace std;
const long long int mod=998244353;

void solve(long long int n){
    string binario;
    cin.ignore();
    getline(cin,binario);
    long long result=1;
    long long temp=1;
    for(long long int i=1;i<n;i++){
        if(binario[i-1]==binario[i]){
            temp=(2*temp)%mod;
        }
        else{
            temp=1;
        }
        result = (result+temp)%mod;
    }
    cout<<result<<endl;
}


int main(){
    long long int test=0;
    cin>>test;
    long long int n=0;
    for(long long int i=0;i<test;i++){
        cin>>n;
        solve(n);
    }
    return 0;
}

