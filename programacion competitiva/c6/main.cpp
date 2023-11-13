#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
int solve(int b,int t){
    int bot[b];
    int dist[3601];
    for(int j=0;j<b;j++){
        cin>>bot[b];
    }
    for (int i=0;i<3601;i++) {
        dist[i]=INF;
    }
    queue<int> q;
    q.push(0);
    dist[0]=0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < b; i++) {
            int sum = min(3600, max(0, u + bot[i]));
            if (bot[sum] > bot[u] + 1) {
                q.push(sum);
                bot[sum] = bot[u] + 1;
            }
        }
    }
    for(int i=t;i<3601;i++){
        if(dist[i]!=INF){
            cout<<dist[i]<<" "<<i-t<<endl;
            break;
        }
    }
}


int main(){
    int test=0;
    int boton=0;
    int tiempo=0;
    cin>>test;
    for(int i=0;i<test;i++){
        cout<<solve(boton,tiempo);
    }
    return 0;
}



