#include <bits/stdc++.h>
using namespace std;

int main(){
    int test=0;
    cin>>test;
    int k=0;

    for(int i=0;i<test;i++){
        cin>>k;
        int result= __gcd(100,k);
        cout<<100/result<<endl;
    }

    return 0;
}