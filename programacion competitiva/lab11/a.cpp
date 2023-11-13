#include <bits/stdc++.h>
using namespace std;

vector<long long int>prefixs(string s){
    vector<long long int>result(s.length());
    for(long long int i=1;i<s.length();i++){
        long long int temp=result[i-1];
        while(temp>0 && s[i]!=s[temp]){
            temp=result[temp-1];
        }
        if(s[i]==s[temp]) temp++;
        result[i]=temp;
    }
    return result;
}

void solve(string s){
    vector<long long int>pf=prefixs(s);
    vector<long long int>r;
    long long int f=pf[s.size()-1];
    while(f>0){
        r.push_back(f);
        f = pf[f-1];
    }
    sort(r.begin(), r.end());
    for(long long int i=0;i<r.size();i++){
        cout<<r[i]<<" ";
    }
};

int main(){
    long long int n=0;
    string s;
    getline(cin,s);
    solve(s);

    return 0;
}

