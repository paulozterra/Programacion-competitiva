#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e15;

struct edge {
    long long int u,v;
    long long int weight;
    edge(long long int _u,long long int _v, long long int _w){
        u= _u;
        v= _v;
        weight= _w;
    }
};

bool edge_cmp(const edge &a, const edge &b){
    return a.weight < b.weight;
}
class DS {
    vector<long long int>parent;
    vector<long long int>rank;

public:
    DS(long long int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(long long int i=0;i<n;i++) {
            parent[i] = i;
        }
    }

    long long int find_set(long long int x){
        if(parent[x]!=x){
            parent[x]=find_set(parent[x]);
        }
        return parent[x];
    }

    void union_set(long long int x,long long int y) {
        x=find_set(x);
        y=find_set(y);
        if(x!=y) {
            if(rank[x]<rank[y])
                swap(x,y);
            parent[y]=x;
            rank[x]+=rank[x]==rank[y];
        }
    }
};

vector<edge>mst(long long int n,vector<edge>edges) {
    DS uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for(long long int i = 0; i < edges.size(); i++) {
        long long int u = edges[i].u, v = edges[i].v;

        if(uf.find_set(u) != uf.find_set(v)) {
            uf.union_set(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}
int main(){
    long long int n = 0, m = 0;
    long long int a = 0, b = 0, w = 0;
    cin >> n >> m;
    vector<edge> edg[n];
    for(long long int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edg[a - 1].push_back(edge(a - 1, b - 1, w));
        edg[b - 1].push_back(edge(b - 1, a - 1, w));
    }
    vector<edge> edges;
    for(long long int i=0; i<n; i++) {
        edges.insert(edges.end(), edg[i].begin(), edg[i].end());
    }
    vector<edge>mm=mst(n,edges);
    long long int sum=0;
    if(mm.size()==n-1){
        for(long long int i=0;i<mm.size(); i++){
            sum+=mm[i].weight;
        }
        cout<<sum<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
} //
