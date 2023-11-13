#include <bits/stdc++.h>


using namespace std;

struct edge {
    long long int u, v;
    long long int weight;

    edge(long long int _u,long long int _v,long long int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

bool edge_cmp(const edge& a, const edge& b) {
    return a.weight < b.weight;
}

class DS {
    vector<long long int> parent;
    vector<long long int> rank;

public:
    DS(long long int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(long long int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    long long int find_set(long long int x){
        if(parent[x]!=x){
            parent[x]=find_set(parent[x]);
        }
        return parent[x];
    }

    void union_set(long long int x, long long int y) {
        long long int tempx=find_set(x);
        long long int tempy=find_set(y);
        if(tempx!=tempy){
            if(rank[tempx]<rank[tempy]){
                parent[tempx]=tempy;
            }
            else if(rank[tempx]>rank[tempy]){
                parent[tempy]=tempx;
            }
            else{
                parent[tempy]=tempx;
                rank[tempx]++;
            }
        }
    }
};

long long int dfs(long long int nd, const vector<edge>& edges, vector<bool>& visited){
    long long int count = 1;
    stack<long long int>s;
    s.push(nd);

    while(!s.empty()){
        long long int temp=s.top();
        s.pop();
        if(!visited[temp]){
            visited[temp]=true;
            for(const edge& e:edges){
                if(e.u==temp && !visited[e.v]){
                    s.push(e.v);
                    count++;
                }
                else if (e.v==temp && !visited[e.u]){
                    s.push(e.u);
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    long long int n=0, m=0;
    long long int a=0, b=0, w=0;
    cin>>n>>m;

    vector<edge>edges;
    for(long long int i=0; i<m; i++){
        cin>>a>>b>>w;
        edges.push_back(edge(a - 1, b - 1, w));
    }

    sort(edges.begin(), edges.end(), edge_cmp);

    DS uf(n);
    long long int count=0;
    long long int sum=0;

    for(const edge& e:edges){
        long long int u=e.u, v=e.v;
        if(uf.find_set(u)!=uf.find_set(v)){
            uf.union_set(u, v);
            sum+=e.weight;
            count++;
            if(count==n-1){
                break;
            }
        }
    }

    if(count==n-1){
        vector<bool>visited(n, false);
        long long int connected=dfs(0, edges, visited);

        if(connected==n){
            cout<<sum<<endl;
        }
        else {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    else {
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}