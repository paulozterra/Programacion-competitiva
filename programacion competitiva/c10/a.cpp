#include <bits/stdc++.h>
using namespace std;

struct union_find{
    vector<int>parent;
    union_find(int n){
        parent = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x]==x){
            return x;
        }
        else{
            parent[x]=find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x,int y){
        parent[find(x)]=find(y);
    }
};
int main() {
    int n=0;
    int m=0;
    int a=0;
    int b=0;
    cin>>n>>m;
    union_find u(n+1); //O(n)
    for(int i=0;i<m;i++){
        cin>>a>> b;
        u.unite(a, b);//O(m)
    }
    bool flag=false;
    for(int j=2;j<n+1;j++){
        if(u.find(j)!=u.find(1)){
            flag=true;
            cout<<j<<endl;
        }
    }
    if(flag==false){
        cout <<"Connected"<<endl;
    }
    //complejidad O(n+m)
    return 0;
}
