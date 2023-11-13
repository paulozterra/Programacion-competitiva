#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXI=(1e5)+2;
const ll inf=1e18;
ll t[4*MAXI];
ll mval[4*MAXI];
int mcount[4*MAXI];

void join(int v){
    mval[v] = min(mval[2*v], mval[2*v+1]);

    if(mval[2*v]==mval[2*v+1]){
        mcount[v]=mcount[2*v]+mcount[2*v+1];
    }
    else if(mval[2*v]<mval[2*v+1]){
        mcount[v]=mcount[2*v];
    }
    else{
        mcount[v]=mcount[2*v+1];
    }
}

void build(ll a[],int v,int l,int r){
    if(l==r){
        t[v]=a[l];
        mval[v]=a[l];
        mcount[v]=1;
    }
    else{
        int m=l+(r - l)/2;
        build(a,2*v,l,m);
        build(a, 2*v+1,m+1,r);
        join(v);
    }
}

pair<ll,int>sum(int v,int tl,int tr,int l,int r){
    if(l>r){
        return{inf, 0};
    }
    if(l==tl && r==tr) {
        return{mval[v], mcount[v]};
    }
    int tm=tl+(tr-tl)/2;
    pair<ll,int>left=sum(2*v,tl,tm,l,min(r,tm));
    pair<ll,int>right = sum(2*v+1,tm+1,tr,max(l,tm+1),r);

    if(left.first==right.first){
        return {left.first,left.second+right.second};
    }
    else if(left.first<right.first){
        return left;
    }
    else{
        return right;
    }
}

void update(int v,int tl,int tr,int pos,ll new_value){
    if(tl==tr){
        t[v]=new_value;
        mval[v]=new_value;
    }
    else{
        int tm=tl+(tr-tl)/2;
        if(pos<=tm) update(2*v,tl,tm,pos,new_value);
        else update(2*v+1,tm+1,tr,pos,new_value);
        join(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    ll a[n];
    for(int i=0; i<n;i++) cin>>a[i];
    build(a,1,0,n-1);
    int op,l,r;
    ll v;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op==2){
            cin>>l>>r;
            pair<ll,int>result=sum(1,0,n - 1,l,r - 1);
            cout<<result.first<<" "<<result.second<<"\n";
        }
        else{
            cin>>l>>v;
            update(1,0,n - 1,l,v);
        }
    }

    return 0;
}