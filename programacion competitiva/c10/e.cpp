#include <bits/stdc++.h>
using namespace std;
const long long int MAXI=(1e6)+2;
long long int t[4*MAXI];

long long int join(long long int a,long long int b){
    return a+ b;
}

void build(long long int a[],long long int v,long long int l,long long int r){
    if(l==r){
        t[v]=a[l];
    }
    else{
        long long int m=l+(r-l)/2;
        build(a,2*v,l,m);
        build(a,2*v+1,m+1,r);
        t[v]=join(t[2*v],t[2*v+1]);
    }
}

long long int sum(long long int v,long long int tl,long long int tr,long long int l,long long int r){
    if(l>r) return 0;
    if(l==tl&& r==tr) return t[v];
    long long int tm= tl+(tr-tl)/2;

    long long int s1=sum(2*v  ,tl  ,tm,l,min(r,tm));
    long long int s2=sum(2*v+1,tm+1,tr,max(tm+1,l) ,r);

    return join(s1,s2);
}

void update(long long int v,long long int tl,long long int tr,long long int pos){
    if(tl==tr){
        if(t[v]==1) t[v]=0;
        else t[v]=1;
    }
    else{
        long long int tm=tl+(tr-tl)/2;
        if(pos<=tm) {
            update(2 * v, tl, tm, pos);
        }
        else{
            update(2*v+1,tm+1,tr,pos);
        }
        t[v]=join(t[2*v],t[2*v+1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n=0;
    long long int m=0;
    cin>>n>>m;
    long long int a[n];
    for(long long int i=0;i<n;i++) a[i]=0;
    build(a,1,0,n-1);
    long long int l=0,r=0;
    char tq;
    long long int pos;
    long long int new_value;
    for( long long int i=0;i<m;i++){
        cin>>tq;
        if(tq=='C'){
            cin>>l>>r;
            cout<<sum(1,0,n-1,l-1,r-1)<<"\n"; // funcion sum cambio l -> l-1 \\complejidad O(log n)
        }
        else{
            cin>>pos;
            update(1,0,n-1,pos-1); // funcion update cambio pos->pos-1 \\complejidad O(log n)
        }
    }
    // complejidad O(m*log(n))
    return 0;
}
