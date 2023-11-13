#include <bits/stdc++.h>
using namespace std;


void solve(int n,int m){
    int t1=0,t2=0;
    int x=0, y=0;
    vector<int>adj[n];
    cin.ignore();
    for(int i=0;i<m;i++){
        cin>>t1;
        cin>>t2;
        adj[t1-1].push_back(t2-1);
        adj[t2-1].push_back(t1-1);
    }
    vector<int>values;
    set<int>s;
    for(int i=0;i<n;i++){
        if(adj[i].size()==1){
            values.push_back(adj[i][0]);
            s.insert(adj[i][0]);
        }
    }
    x=s.size();
    std::sort(values.begin(), values.end());
    int temp=values[0];
    int k=0;
    while(temp==values[k]){
        y++;
        k++;
    }
    cout<<x<<" "<<y<<endl;
    adj->clear();
}


int main(){
    int test=0;
    cin>>test;
    int n=0;
    int m=0;
    for(int i=0;i<test;i++){
        cin>>n>>m;
        solve(n,m);
    }
    return 0;

}