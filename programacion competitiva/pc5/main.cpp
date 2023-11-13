#include <bits/stdc++.h>
using namespace std;


int solve(int n,vector<string> v){
    long long int mat[n][n];
    if(v[0][0]=='.' && v.size()==1){
        return 1;
    }
    else if(v[0][0]=='*' || v[n-1][n-1]=='*'){
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    int t1=0;
    while(v[t1++][0]!='*' && t1<n) {
        mat[t1][0]=1;
    }
    int t2=0;
    while(v[0][t2++]!='*' && t2<n){
        mat[0][t2]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(v[i][j]=='*'){
                mat[i][j]=0;
            }
            else{
                mat[i][j]= mat[i-1][j]+mat[i][j-1];
            }
        }
    }
    return mat[n-1][n-1]%1000000007;
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