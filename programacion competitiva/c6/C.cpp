#include <bits/stdc++.h>
using namespace std;


void solve(int n,int m){
    char mat[n][m];
    int a=0;
    int b=0;
    int min=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='A'){
                a=m*i+j;
            }
            else if(mat[i][j]=='B'){
                b=m*i+j;
            }
        }
    }
    vector<int>adj[n*m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i-1][j]!='#' && i-1>=0){
                adj[m*i+j].push_back(m*(i-1)+j);
            }
            if(mat[i][j-1]!='#' && j-1>=0){
                adj[m*i+j].push_back(m*i+j-1);
            }
            if(mat[i+1][j]!='#' && i+1<n){
                adj[m*i+j].push_back(m*(i+1)+j);
            }
            if(mat[i][j+1]!='#' && j+1<m){
                adj[m*i+j].push_back(m*i+j+1);
            }
        }
    }
    bool visited[n*m];
    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (!visited[u]) {
            visited[u] = true;
            for (int v : adj[u]) {
                q.push(v);
            }
        }
    }
    if(visited[b-1]==0){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        cout<<min<<endl;
    }

/*
    for(int i=0;i<n*m;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<a<<" "<<b<<endl;
    for(int i=0;i<n*m;i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;*/

}

int main(){
    int n=0;
    int m=0;

    cin>>n>>m;
    solve(n,m);

    return 0;
}