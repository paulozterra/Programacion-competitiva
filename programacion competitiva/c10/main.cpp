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
    int a=0;
    int b=0;
    int cam=0;
    cin>>n;
    union_find u(n+1);
    for(int i=1;i<n-1;i++){
        cin>>a>> b;
        u.unite(a, b);
    }
    for(int j=1;j<n-1;j++){
        if(u.find(j)!=j){
            cam+=1;
        }
    }

    cout<<cam-1;

    return 0;
}
