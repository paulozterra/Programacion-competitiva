#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXI=(1e5)+2;
ll t[4*MAXI];

ll join(ll a,ll b){
    return max(a,b);
}

void build(ll a[],int v,int l,int r){
    if(l==r) t[v]=a[l];
    else{
        int m=l+(r-l)/2;
        build(a,2*v,l,m);
        build(a,2*v+1,m+1,r);
        t[v]=join(t[2*v],t[2*v+1]);
    }
}

ll   sum(int v,int tl,int tr,int l,int r){
    /// sum of elements in [l,r] contained(if valid) in vertex v:[tl,tr]
    if(l>r) return 0; // tbm usar inf
    if(l==tl&& r==tr) return t[v];
    int tm= tl+(tr-tl)/2;

    ll s1=sum(2*v  ,tl  ,tm,l           ,min(r,tm)); /// intersection [l,r] and [l   ,tm]
    ll s2=sum(2*v+1,tm+1,tr,max(tm+1,l) ,r        ); /// intersection [l,r] and [tm+1, r]

    return join(s1,s2);
}

void update(int v,int tl,int tr,int pos,ll new_value){
    if(tl==tr) t[v]=new_value;
    else{
        int tm=tl+(tr-tl)/2;
        if(pos<=tm)
            update(2*v  ,tl  ,tm,pos,new_value);
        else
            update(2*v+1,tm+1,tr,pos,new_value);
        t[v]=join(t[2*v],t[2*v+1]);
    }
}

void imprimir(int n){
    for(int i=0;i<n;i++)
        cout<<t[i]<<"\n "[i+1<n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    build(a,1,0,n-1);
    //imprimir(4*n);
    cout<<sum(1,0,n-1,0,n)<<"\n";

    for(int i=0;i<m;i++){
        int pos;
        ll new_value;
        cin>>pos>>new_value;
        update(1,0,n,pos,new_value);
        cout << sum(1,0,n-1,0,n) << "\n";
    }
    return 0;
}
