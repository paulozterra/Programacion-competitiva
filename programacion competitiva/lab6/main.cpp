#include <bits/stdc++.h>
using namespace std;

int main(){
    int e=0;
    int v=0;
    int c1=0;
    int c2=0;
    cin>>e>>v;
    vector<int>adj[v];
    int dist[e];
    for(int i=0;i<v;i++){
        cin>>c1>>c2;
        adj[c1-1].push_back(c2-1);
        adj[c2-1].push_back(c1-1);
    }
    bool visited[v];
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        cout<<"front: "<<u<<endl;
        q.pop();

        if (!visited[u]) {
            visited[u] = true;
            for (int v : adj[u]) {
                q.push(v);
                cout<<"push: "<<v<<endl;

            }
        }
    }
    if(!visited[e - 1]){
        cout<<"IMPOSSIBLE"<<endl;
    }
    for(int i=0;i<v;i++){
        cout<<visited[i]<<" ";
    }


    return 0;
}