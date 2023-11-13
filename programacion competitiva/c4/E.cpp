#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=0;
    cin>>x;
    int n=0;
    int k=0;
    int count=0;
    int sum=0;
    vector<int>v;
    while(x--){
        cin>>n;
        for(int i=0;i<3*n;i++){
            cin>>k;
            v.push_back(k);
        }
        sort(v.begin(),v.end());

        for(int j=v.size()-2;j>n/3;j=j-2){
            sum+=v[j];
        }
        cout<<sum<<"\n";
        sum=0;
        v.clear();
    }

    return 0;
}