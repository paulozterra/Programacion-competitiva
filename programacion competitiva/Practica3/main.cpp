#include <bits/stdc++.h>
using namespace std;

int solve1(vector<long long int>&v1,long long x){
    long long int lo=0,hi=v1.size()-1;
    long long int temp=0;
    if(v1[0]>x){
        return v1.size();
    }
    while(lo<=hi){
        long long int m=(lo+hi)/2;
        temp = m;
        if(v1[m]==x) return v1.size()-m;
        else if(x<v1[m]){hi=m-1;}
        else if(x>v1[m]){lo=m+1;}
    }

    return v1.size()-temp-1;
}


int main(){
    vector<long long int>v1;

    long long int n{};
    long long int q{};
    long long int d{};
    long long int x{};
    cin>>n>>q;
    for(long long int i=0;i<n;i++){
        cin>>d;
        v1.push_back(d);
    }
    std::sort(v1.begin(), v1.end());
    for(long long int j=0;j<q;j++){
        cin>>x;
        cout<<solve1(v1,x)<<endl;
    }
    return 0;
}
