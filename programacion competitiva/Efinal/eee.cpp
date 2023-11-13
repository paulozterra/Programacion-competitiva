#include <bits/stdc++.h>
using namespace std;
const long long int P=1e4;
const long long int INF=1e15;
long long int p=0;
long long int t=0;

vector<pair<long long int, long long int>>adj[P];
vector<pair<long long int, long long int>>par[P];
bool visited[P];
long long int dist[P];

bool compare(const pair<long long int, long long int>& a, const pair<long long int, long long int>& b) {
    return a.second<b.second;
}

void dijkstra(){  // realizamos un dijsktra para encontrar caminos minimos //complejidad: O((V + E) log V)
    memset(visited,false,sizeof(visited));
    for(long long int i=0;i<p;i++){ // O(p)
        dist[i]=INF;
    }
    priority_queue<pair<int, int>>q;
    dist[0]=0;
    q.push({0, 0});
    while(!q.empty()){
        long long int u=q.top().second;
        q.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        for(auto[v, w]:adj[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                par[v].clear();
                par[v].push_back({u,w});
                q.push({-dist[v],v});
            }
            else if(dist[u]+w==dist[v]){
                par[v].push_back({u,w});
            }
        }
    }
}

long long int BFS(){ // complejidad O(V + E)
    memset(visited,false,sizeof(visited));
    queue<long long int>q;
    q.push(p-1);
    long long int l=0;
    while(!q.empty()){
        long long int u=q.front();
        q.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        for(auto[v, w]:par[u]){
            l+=w;
            q.push(v);
        }
    }
    return l;
}

int main() {
    long long int u=0;
    long long int v=0;
    long long int w=0;
    cin>>p>>t;
    for(long long int i=0;i<t;i++){ //O(t)
        cin>>u>>v>>w;
        if(u==v){
            continue;
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(long long int i = 0; i < p; i++){ //O(p)
        sort(adj[i].begin(),adj[i].end(),compare);
    }
    dijkstra();
    long long int result=2*BFS();
    cout<<result<<endl;
    return 0;
}
//complejidad   O((V + E) log V)  definido por el algoritmo de dijkstra