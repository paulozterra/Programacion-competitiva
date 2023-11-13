#include <bits/stdc++.h>
using namespace std;
vector<int>v1;

int solve(vector<int>v){
    sort(v.begin(),v.end());
    if(v.size()==1){
        return 1;
    }
    else if(v[0]==v[v.size()-1]){
        return v.size();
    }
    else{
        int result{};
        for(int i=0;i<v.size();i++){
            if(v1[i]==v[v.size()-1]){
                result=i+1;
                break;
            }
        }
        return result;
    }

}
int main(){
    int n{};
    int k{};
    int m{};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;

        for(int j=0;j<k;j++){
            cin>>m;
            v1.push_back(m);
        }
        cout<<solve(v1)<<endl;
        v1.clear();

    }
    return 0;
}