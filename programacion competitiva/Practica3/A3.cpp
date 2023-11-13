#include <bits/stdc++.h>
using namespace std;
vector<long long int>v1;


int solve(vector<long long int>v,long long int lo,long long int hi,long long int x){
    int n = (hi+lo)/2;

    if(lo>hi)
        return v1.size()-n-1;
    if(v[n]==x){
        return v1.size()-n;
    }
    else if(v[n]<x) return solve(v,n+1,hi,x);
    else if(v[n]>x) return solve(v,lo,n-1,x);
}



int main(){
    long long int n{};
    long long int q{};
    long long int d{};
    long long int x{};
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>d;
        v1.push_back(d);
    }
    std::sort(v1.begin(), v1.end());
    for(int j=0;j<q;j++){
        cin>>x;
        cout<<solve(v1,0,v1.size(),x)<<endl;
    }
    return 0;
}
