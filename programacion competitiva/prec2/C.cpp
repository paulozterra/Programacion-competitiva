#include <bits/stdc++.h>
using namespace std;
vector<long long int>magicos;
string temp1;
long long int index=0;
long long int n{};

int recur(long long int min,long long int max,long long int index){
    long long int num{};
    int boo=1;
    long long int b=max-index;
    temp1 = to_string(b);

    if(min>b){
        return magicos.size();
    }
    for(int i=0;i<n;i++){
        char t=temp1[n-i-1];
        int t2=t-48;
        num=num+t2*pow(10,i);
        if(num%(i+1)!=0){
            boo*=0;
            goto end;
        }
        else{

        }

    }
    end:
    if(boo==1){
        magicos.push_back(num);
    }
    num=0;
    recur(min,max,index+1);
}

int solve(){
    long long int min=pow(10,n-1);
    long long int max=0;
    for(int i=0;i<n;i++){
        max+=9*pow(10,i);
    }
    temp1= to_string(max);
    int r=recur(min,max,index);
    return r;
}

int main(){

    cin>>n;
    if(n>30){
        cout<<0;
    }
    else{
        cout<<solve();
    }
    return 0;
}//
// Created by pauloz on 16/04/2023.
//

