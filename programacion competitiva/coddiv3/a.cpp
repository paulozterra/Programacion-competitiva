#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>arr){
    int max=0;
    std::sort(arr.begin(), arr.end());
    if(arr.size()==1){
        return arr[0]-arr[0];
    }
    else if(arr.size()==2){
        return arr[1]-arr[0];
    }
    else if(arr.size()==3){
        return (arr[2]-arr[0]);
    }
    else{

        for (int i = 0; i < (arr.size() / 2); i++) {
            max += (arr[arr.size() - i - 1] - arr[i]);
        }
        return max;


    }



}


int main(){
    int test=0;
    int n=0;
    int ai=0;
    cin>>test;
    vector<int>arr;
    for(int i=0;i<test;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>ai;
            arr.push_back(ai);

        }
        cout<<solve(arr)<<endl;
        arr.clear();
    }
    return 0;
}

