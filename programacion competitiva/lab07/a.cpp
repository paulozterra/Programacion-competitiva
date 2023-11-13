#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;
struct edge {
    long long int u,v;
    long long int weight;
    edge(long long int _u,long long int _v, long long int _w){
        u= _u;
        v= _v;
        weight= _w;
    }
};

int main() {
    long long int n = 0, m = 0;
    long long int a = 0, b = 0, w = 0;
    cin >> n >> m;
    vector<edge> edg[n];
    for (long long int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edg[a - 1].push_back(edge(a - 1, b - 1, w));
        edg[b - 1].push_back(edge(b - 1, a - 1, w));
    }
    vector<long long int> dist(n, INF);
    vector<long long int> parent(n, -1);
    dist[0] = 0;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        long long int u = pq.top().second,
                d = pq.top().first;
        pq.pop();
        if (d+1 > dist[u]) continue;
        for (long long int i = 0; i < edg[u].size(); i++) {
            long long int v = edg[u][i].v,
                    w = edg[u][i].weight;
            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    long long int p = 0;
    long long int temp = n - 1;
    vector<long long int> camino;
    while (p != -1 && parent[n - 1] != -1) {
        p = parent[temp];
        camino.push_back(temp);
        temp = p;
    }
    if (camino.size() == 0) {
        cout << -1 << endl;
    }
    else {
        for (long long int i = camino.size() - 1; i >= 0; i--) {
            cout << camino[i] + 1 << " ";
        }
    }

    return 0;

}

