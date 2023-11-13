#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>&v){
    int count=0;
    int max=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            count++;
        }
        else{
            if(count>max){
                max=count;
            }
            count=0;
        }
    }
    if(count>max){
        max=count;
    }
    return max;
}

int main(){
    int n=0;
    cin>>n;
    int m=0;
    int val=0;
    vector<int>v;

    for(int i=0;i<n;i++) {
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>val;
            v.push_back(val);
        }

        cout<<solve(v)<<endl;
        v.clear();

    }
    return 0;
}