#include <bits/stdc++.h>
using namespace std;


int solve(int n,vector<string> v){
    int result=0;
    int mat[n][n] {};
    if(v[0][0]=='*' || v[n-1][n-1]=='*'){
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

        }
    }

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