#include <bits/stdc++.h>
using namespace std;
int s(int a,vector<int>u){
    int f=0;
    for(int i=0;i<u.size();i++) if(u[i]==a) f=1;
    return f;
}
int d(int b,long long int e){
    vector<int>u;
    int y=1,j=10;
    string r;
    while(j>0) {
        y *= b;
        r = to_string(y);
        int t = r[r.size() - 1] - 48;
        if (!s(t, u)) u.push_back(t);
        else break;
        j--;
    }
    int ix= (e-1)%u.size();
    int t=u[ix];
    return t;
}
int main(){
    int n{},b{};
    long long int e{};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b>>e;
        if(b==0) cout<<0<<endl;
        else if(e==0) cout<<1<<endl;
        else cout<<d(b,e)<<endl;
    }
    return 0;
}
