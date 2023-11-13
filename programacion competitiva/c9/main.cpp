#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;

long long int solve(long long int d){
    long long int result=0;
    if(d==0) return 1;
    long long int r=((solve(d/2))%mod);
    result=(r*r)%mod;
    if(d%2==1) result=(result*9)%mod;
    return result;
}
int main(){
    long long int test=0;
    long long int d=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        long long int result=0;
        cin>>d;
        result=(solve(d-1)*8)%mod;
        cout<<result<<endl;

    }
    return 0;
}
