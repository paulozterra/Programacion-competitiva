#include <bits/stdc++.h>
using namespace std;


int solve(int n,vector<string> v){
    if(v[0][0]=='*' || v[n-1][n-1]=='*'){
        return 0;
    }
    int count=0;
    stack<pair<int,int>> s;
    char mat[n][n];
    int val[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=v[i][j];
            val[i][j]=0;
        }
    }

    s.push({0,0});
    vector<pair<int,int>>c;
    vector<pair<int,int>>sc;
    while(!s.empty()){
        pair<int,int>temp = s.top();
        int y=temp.second;
        int x=temp.first;

        //cout<<x<<"-"<<y<<endl;
        c.push_back(temp);
        s.pop();
        if(y==(n-1) && x==(n-1)){
            for(int i=0;i<c.size();i++){
                val[c[i].first][c[i].second]=1;
                //cout<<"pintado: "<<c[i].first<<"."<<c[i].second<<" ";
            }
            c.clear();
            count++;
            //cout<<endl;
            continue;
        }
        //cout<<endl;

        if(mat[x][y+1]=='.' && y+1<n){
            if(val[x][y+1]==1) {
                for (int i = 0; i < c.size(); i++) {
                    val[c[i].first][c[i].second]= 1;
                    //cout<<"pintado: "<<c[i].first<<"."<<c[i].second<<" ";
                }
                c.clear();
                //cout << endl;
                count++;

            }
            else{
                if(sc.size()!=0){
                    int e=0;
                    for(int i=0;i<sc.size();i++){
                        if(sc[i].first==x && sc[i].second==y+1){
                            e=1;
                            break;
                        }
                    }
                    if(e==0){
                        s.push({x,y+1});
                    }
                }
                else{
                    s.push({x,y+1});
                }
            }
        }
        //cout<<endl;

        if(mat[x+1][y]=='.' && x+1<n){
            if(val[x+1][y]==1){
                for(int i=0;i<c.size();i++){
                    val[c[i].first][c[i].second]=1;
                    // cout<<"pintado: "<<c[i].first<<"."<<c[i].second<<" ";
                }
                //cout<<endl;
                c.clear();
                count++;

            }
            else {
                if (sc.size() != 0) {
                    int e = 0;
                    for (int i = 0; i < sc.size(); i++) {
                        if (sc[i].first == x+1 && sc[i].second == y) {
                            e = 1;
                            break;
                        }
                    }
                    if (e == 0) {
                        s.push({x+1,y});
                    }
                }
                else {
                    s.push({x+1,y});
                }
            }
        }
        if(mat[x][y+1]=='*' && mat[x+1][y]=='*'){
            sc.push_back(temp);
            c.clear();
        }
    }
/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout<<mat[i][j]<<" ";
        }
        //cout<<endl;
    }
    //cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout<<val[i][j]<<" ";
        }
        //cout<<endl;
    }
    */
    long long int result= count;
    return result;
}
int main(){
    vector<string>v;
    int n=0;
    cin>>n;
    string s;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        v.push_back(s);
    }

    cout<<solve(n,v);

    return 0;
}