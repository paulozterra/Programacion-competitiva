#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;
// estructura de edges
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
// se realiza una clase para disjoin set
class DS {
    vector<int>parent;
    vector<int>rank;

public:
    DS(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }

    int find_set(int x){
        if(parent[x]!=x){
            parent[x]=find_set(parent[x]);
        }
        return parent[x];
    }

    void union_set(int x, int y) {
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
// se realiza un mst para obtener vector de edges el cual nos servira para sumar la distancia minima
vector<edge>mst(int n,vector<edge>edges) {  // complejidad  O(m log m)
    DS uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;

        if(uf.find_set(u) != uf.find_set(v)) {
            uf.union_set(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}
// se realiza un dfs para saber si se recorrieron todos los nodos
// en caso contrario se imprime imposible
void dfs(int nd, vector<edge>& edges, vector<bool>& visited) { // complejidad O(n + m)
    stack<int>s;
    s.push(nd);

    while(!s.empty()){
        int temp=s.top();
        s.pop();
        if(!visited[temp]){
            visited[temp]=true;
            for(const edge& e : edges){
                if(e.u==temp && !visited[e.v]){
                    s.push(e.v);
                }
                else if(e.v==temp && !visited[e.u]) {
                    s.push(e.u);
                }
            }
        }
    }
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
    for(int i=0; i<n; i++) {
        edges.insert(edges.end(), edg[i].begin(), edg[i].end());
    }
    vector<edge>mm=mst(n,edges);
    int sum=0;
    vector<bool>visit(n,false);
    dfs(0,edges,visit);
    int conect=1;

    for(int i=0;i<visit.size();i++){
        if(visit[i]==false){
            cout<<"IMPOSSIBLE"<<endl; // si no estan conectados ( resultado obtenido por el dfs) retornamos imposible
            conect=0;
            break;
        }
    }
    // en caso esten todos conectados se suma todos los pesos y obtener el resultado
    if(conect==1){
        for(int i=0;i<mm.size(); i++){
            sum+=mm[i].weight;
        }
        cout<<sum<<endl;
    }

    // complejidad O(m log m)
    return 0;
} //