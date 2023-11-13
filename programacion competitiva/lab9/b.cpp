#include <bits/stdc++.h>
using namespace std;
vector<long long int> dp(1000001,-1);
const long long int mod=1e9+7;

// se guarda los factoriales para usarlos posteriormente. Complejidad O(a)
void solve(){
    dp[0]=1;
    for(long long int i=1;i<1e6+1;i++){
        dp[i]=(dp[i-1]*i)%mod;
    }
}
long long int pot(long long int x, long long int y) {
    long long int result=0;
    if(y==0) return 1;
    long long int r=((pot(x,y/2))%mod);
    result=(r*r)%mod;
    if(y%2==1) result=(result*x)%mod;
    return result;
}

int main(){
    long long int test=0;
    long long int a=0;
    long long int b=0;
    long long int result=0;
    long long int result1=0;
    long long int result2=0;
    solve();
    cin>>test;
    for(long long int i=0;i<test;i++){ // complejidad O(test)
        cin>>a>>b;
        //O(a)
        result1=dp[a];  //O(1) una vez ya calculados
        result2=(pot(dp[b],mod-2)*pot(dp[a-b],mod-2))%mod; //inversa multiplicativa modular
        result=(result1*result2)%mod;
        cout<<result<<endl;
    }
    //complejidad total O(a*test)
    return 0;
}//