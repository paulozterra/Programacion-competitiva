#include <bits/stdc++.h>
using namespace std;

void solve(int m){

    if(m==3){
        cout<<"2 1 3";
    }
    else if(m%2==0){
        int mat[m];

        for(int i=0;i<m-2;i=i+2){
            mat[i]=i+2;
            mat[i+1]=i+1;
        }
        mat[m-1]=m;
        mat[m-2]=m-1;
        for(int i=0;i<m;i++){
            cout<<mat[i]<<" ";
        }
        return;

        }
    else{
        int mat[m];
        for(int i=1;i<m-2;i=i+2){
            mat[i]=i+2;
            mat[i+1]=i+1;
        }
        mat[0]=1;
        mat[m-1]=m;
        mat[m-2]=m-1;
        for(int i=0;i<m;i++){
            cout<<mat[i]<<" ";
        }
        return;
        }
    return;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n=0;
    int m=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        solve(m);
        cout<<"\n";
    }
    return 0;
}