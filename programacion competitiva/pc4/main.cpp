#include <bits/stdc++.h>
using namespace std;

int solve(vector< long long int>&v, long long int k){
    long long int r{};
    sort(v.begin(),v.end());
    long long int j=v[v.size()-1]-1000;
    for( long long int i=v.size();i>0;i--){
        if(v[i]==j){
            r=i-1;
            break;
        }
        else if(v[i]<j){
            r=i;
            break;
        }
    }
    if(k<r || r==0){
        return k;
    }
    return r;
}

int main(){
    long long int n{};
    long long int k{};
    vector< long long int>v;
    cin>>n>>k;
    long long int temp{};
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    cout<<solve(v,k);
    return 0;
}