#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0;
    int k=0;
    cin>>n>>k;
    int t=0;
    vector<int>temp;
    for(int i=0;i<n;i++){
        cin>>t;
        temp.push_back(t);
    }
    int dp[n];
    dp[0]=0;
    dp[1]=temp[1]-temp[0];
    for(int i=2;i<n;i++){
        for(int j=i;j<k;j++){
            dp[i+1]=min(dp[i]+abs(temp[j+1]-temp[j+2]), dp[i]+abs(temp[j+1]-temp[j+2])
        }
    }


    return 0;
}

