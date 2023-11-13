#include <bits/stdc++.h>
using namespace std;


void solve(vector<int>&vec,int n,int index){

    if(n==index){
        return;
    }
    if(vec[index]==1){
        if(index!=0 && index+1!=n){
            if(vec[index-1]==-1){
                vec[index-1]+=1;
                vec[index]=0;
            }
            else if(vec[index+1]==-1){
                vec[index+1]+=1;
                vec[index]=0;
            }
        }
        else{
            if(vec[index-1]==-1){
                vec[index-1]+=1;
                vec[index]=0;
            }
        }
    }

    solve(vec,n,index+1);

}

int main(){
    int n_equip{};
    int n_d{};
    int n_r{};
    int index=0;
    cin>>n_equip>>n_d>>n_r;
    vector<int>vec(n_equip,0);
    for(int d=0;d<n_d;d++){
        int n{};
        cin>>n;
        vec[n-1]=vec[n-1]-1;
    }
    for(int r=0;r<n_r;r++){
        int m{};
        cin>>m;
        vec[m-1]++;
    }

    solve(vec,n_equip,index);
    int sum{};
    for(int i=0;i<n_equip;i++){
        if(vec[i]==-1){
            sum++;
        }
    }
    cout<<sum;

    return 0;
}