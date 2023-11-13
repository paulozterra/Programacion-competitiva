#include <bits/stdc++.h>
using namespace std;

int solve(string &m,string &s){
    //cout<<m<<endl;
    int count=0;
    for(int i=0;i<10;i++){
        //cout<<s[i]<<"|"<<m[i]<<endl;
        if(s[i]!=m[i]){
            count++;
        }
        //cout<<"c: "<<count<<endl;
    }
    return count;
}

int main(){
    int n=0;
    string s="codeforces";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string m;
        getline(cin,m);
        cout<<solve(m,s)<<endl;
    }
    return 0;
}