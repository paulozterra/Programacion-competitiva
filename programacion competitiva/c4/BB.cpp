#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<long long int>&v1,vector<long long int>&v2){
    long long int sum=0;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(long long int i=0;i<v1.size();i++){
        sum+=v1[i]*v2[v2.size()-1-i];
    }
    return sum;
}

int main(){
    long long int n=0;
    cin>>n;
    vector<long long int>v1;
    vector<long long int>v2;
    long long int m=0;
    long long int k=0;
    for(long long j=0;j<n;j++){
        cin>>m;
        for(long long int i=0;i<m;i++){
            cin>>k;
            v1.push_back(k);
        }
        for(long long int i=0;i<m;i++){
            cin>>k;
            v2.push_back(k);
        }
        cout<<"case #"<<j+1<<": "<<solve(v1,v2)<<endl;
        v1.clear();
        v2.clear();
    }
    return 0;
}