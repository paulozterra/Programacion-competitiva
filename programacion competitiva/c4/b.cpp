#include <bits/stdc++.h>
using namespace std;

void solve(int m){
    if(m==4){
        cout<<"2 1 3 4";
        return;
    }
    else if(m==3){
        cout<<"2 1 3";
    }
    else if(m%2==0){
        int n2=m/2;
        int n1=n2-1;
        int mat[m-1];

        for(int i=0;i<m;i++){
            if(i+1>=n1){
                mat[i]=i+3;
            }
            else{
                mat[i]=i+1;
            }
        }
        mat[m-1] = m;
        mat[m-2] = n2;
        mat[m-3] = n1;
        for(int i=0;i<m;i++){
            cout<<mat[i]<<" ";
        }
        return;

    }
    else{

        for(int i=0;i<m;i++){
            cout<<i+1<<" ";
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