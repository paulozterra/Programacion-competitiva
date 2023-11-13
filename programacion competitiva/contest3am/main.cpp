#include <bits/stdc++.h>
using namespace std;

int solve(string s1,string s2){
    if(s1==s2){
        return 0;
    }
    else{

    }
}

int main(){
    int test=0;
    string s1;
    string s2;
    cin>>test;
    cin.ignore();
    for(int i=0;i<test;i++){
        getline(cin,s1);
        getline(cin,s2);
        cout<<solve(s1,s2)<<endl;
    }

    return 0;
}

