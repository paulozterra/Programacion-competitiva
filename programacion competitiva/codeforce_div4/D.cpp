#include <bits/stdc++.h>
using namespace std;


int solve(long long int n,long long int m){
    vector<long long int>v;
    if(n%3!=0){
        return 0;
    }
    else{
        v.push_back(n/3);
        v.push_back(2*n/3);
        for(int i=0;i<v.size();i++){
            if(v[i]%3==0){
                v.push_back(v[i]/3);
                v.push_back(2*v[i]/3);
            }
        }
        for(long long int i=0;i<v.size();i++){
            if(v[i]==m){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int t=0;
    long long int n=0;
    long long int m=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        if(m>n){
            cout<<"NO"<<endl;
            continue;
        }
        else if(m==n==1){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            int r= solve(n,m);
            if(r==1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
