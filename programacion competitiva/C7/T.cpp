//
// Created by pauloz on 3/06/2023.
//

#include <bits/stdc++.h>
using namespace std;

const long long int INF = 1e15;
//estructura edge
struct edge {
    long long int u;
    long long int v;
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
        // se agregan las conexiones entre vertices
        edg[a].push_back(edge(a, b, w));
        edg[b].push_back(edge(b, a, w));
    }
    // se realiza un djisktra
    vector<long long int> dist(n, INF);
    vector<long long int> parent(n, -1);
    vector<bool>u1(n,false);

    dist[0] = 0;
    //complejidad del djisktra O(m + n log n)
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        long long int u = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (long long int i = 0; i < edg[u].size(); i++) {
            long long int v = edg[u][i].v;
            long long int w = edg[u][i].weight;
            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                parent[v] = u; // se setean los padres para posteriormente utilizarlos
                pq.push({dist[v], v});
            }
        }
    }


    long long int p = 0;
    long long int temp = n - 1;
    vector<long long int> camino; // vector para determinar el camino que se realizo
    //se pushea el camino apartir del ultimo
    while (p != -1 ) {
        p = parent[temp];
        camino.push_back(temp);
        temp = p;
    }



    for (long long int i = camino.size() - 1; i >= 0; i--) {
        cout << camino[i]<< " "; //imprimimos el camino en reversa (el vector estaba del ultimo al primero)
        // del primero al ultimo
    }
    cout<<endl;
    cout<<dist[n-1]*4<<endl;

    return 0;
//
}
