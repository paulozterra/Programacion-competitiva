#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;

long long int solve(long long int d){
    long long int r=8;
    for(int i=1;i<d;i++){
        r*=9;
        r=r%mod;
    }
    return r;
}
int main(){
    long long int test=0;
    long long int d=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        cin>>d;
        long long int result=0;
        result=solve(d)%mod;
        cout<<result<<endl;
    }
    return 0;
}
