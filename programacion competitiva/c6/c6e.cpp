#include <bits/stdc++.h>
using namespace std;

int n=0, m=0;
int mat[1005][1005];
vector<pair<int, int>> adj[1005*1005];
int visited[1005*1005];

void dfs(int u,int& sum){
    visited[u]=1;
    sum+=mat[u/m][u%m];
    for(auto v : adj[u]){
        if(!visited[v.first]){
            dfs(v.first,sum);
        }
    }
}

int solve(){
    for(int i=0;i<n*m;i++){
        adj[i].clear();
        visited[i]=0;
    }
    int p=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p;
            mat[i][j]=p;
            if(p!=0){
                if(mat[i-1][j]!=0 && i>0){
                    adj[i*m+j].push_back({(i-1)*m+j,0});
                    adj[(i-1)*m+j].push_back({i*m+j,0});
                }
                if (mat[i][j-1]!=0 && j>0){
                    adj[i*m+j].push_back({i*m+j-1,0});
                    adj[i*m+j-1].push_back({i*m+j,0});
                }
            }
        }
    }
    int max=0;
    for(int i=0; i<n*m;i++){
        if(!visited[i] && mat[i/m][i%m]!= 0){
            int sum=0;
            dfs(i,sum);
            if(sum>max){
                max=sum;
            }
        }
    }
    return max;
}

int main() {
    int test=0;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>n>>m;
        cout<<solve()<<endl;
    }
    return 0;
}