#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    int temp=0;
    vector<int>vec;
    for(int i=0;i<n;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    int dp[n];
    dp[0]=abs(vec[1]-vec[0]);
    dp[1]=abs(vec[2]-vec[0]);

    if(n%2==0){
        for(int i=0;i<vec.size()-2;i++){
            if(i!=vec.size()-3)
                dp[i+2]=dp[i]+min(abs(vec[i+2]-vec[i+1]),(abs(vec[i+3]-vec[i+1])));
            else{
                dp[i+2]=dp[i]+abs(vec[i+2]-vec[i+1]);
            }
        }
    }
    else{
        for(int i=0;i<vec.size()-3;i++){
            if(i!=vec.size()-3)
                dp[i+2]=dp[i]+min(abs(vec[i+2]-vec[i+1]),(abs(vec[i+3]-vec[i+1])));
            else{
                dp[i+2]=dp[i]+abs(vec[i+2]-vec[i+1]);
            }
        }
    }

    cout<<min(dp[n-2],dp[n-1]);

    return 0;
}
