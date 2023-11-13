#include <bits/stdc++.h>

using namespace std;
const int H=20,W=60;
const long long int INF=1e15;
long long int h=0;
long long int w=0;
long long int arr[H+2][W];
long long int dist[H+2][W];
bool visited[H+2][W];
pair<long long int,long long int> par[H+2][W];

bool valid_pos(pair<int,int>pos){ //validador de posicion
    return 0<=pos.first && 0<=pos.second && pos.first<h+2 && pos.second<w;
}

void solve(){ // djisktra //complejidad: O((V + E) log V)
    for(int i = 0;i < h + 2;i++) // O(h+2)
        fill_n(dist[i], w, INF);
    for(int i = 0;i < h + 2;i++) // O(h+2)
        fill_n(visited[i], w, 0);

    priority_queue<pair<int,pair<int,int>>>q;
    dist[0][0] = 0;
    q.push({0, make_pair(0,0)});
    while(!q.empty()){
        pair<int,int>u=q.top().second;
        q.pop();
        if(visited[u.first][u.second]){
            continue;
        }
        visited[u.first][u.second]=true;
        for(int i=-1;i<2;i++){ // O(3) ↝> O(1)
            for(int j=-1;j<2;j++){ //O(3) ↝> O(1)
                pair<int,int> v = make_pair(u.first+i,u.second+j);
                if (valid_pos(v) && dist[u.first][u.second]+arr[v.first][v.second] < dist[v.first][v.second]) {
                    dist[v.first][v.second] = dist[u.first][u.second] + arr[v.first][v.second]; // verificamos si es una posicion valida
                    par[v.first][v.second] = u;
                    q.push({-dist[v.first][v.second],v});
                }
            }
        }

    }
    for(pair<int,int> v=make_pair(h+1,w-1); v!=make_pair(0,0); v=par[v.first][v.second]){
        arr[v.first][v.second]=0;
    }

}

int main(){
    while(cin>>h && cin>>w){
        if(h==0 && w==0){
            break;
        }
        fill_n(arr[0], w, 0);
        //O(h*w)
        for(int i=1;i<=h;i++){ // O(h)
            for(int j=0;j<w;j++){ // O(w)
                char c;
                cin>>c;
                arr[i][j]=c-48;
            }
        }
        fill_n(arr[h+1],w,0);
        solve(); //dijkstra
        for(int i=1;i<=h;i++){ //O(h)
            for(int j=0;j<w;j++){ //O(w)
                if(arr[i][j]){
                    cout<<arr[i][j];
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}

