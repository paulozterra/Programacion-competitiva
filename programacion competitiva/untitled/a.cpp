#include <bits/stdc++.h>
using namespace std;

void solve(string cad,int n){
    vector<char>result;
    char temp=cad[0];
    for(int i=1;i<n;i++){
        if(temp==cad[i]){
            result.push_back(temp);
            temp=cad[i+1];
            i++;
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
    cout<<endl;
}

int main(){
    int test=0;
    cin>>test;
    int n=0;
    string cad;
    for(int i=0;i<test;i++){
        cin>>n;
        cin.ignore();
        getline(cin,cad);
        solve(cad,n);
    }
    return 0;
}

