#include <bits/stdc++.h>
using namespace std;

void solve(long long int n){
    long long int k=0;
    long long int t1=0;
    long long int t2=0;
    long long int t3=0;
    for(long long int j=0;j<n;j++){
        cin>>k;
        if(j==0){
            t1=k;
            t2=k;
            cout<<1;
        }
        else{
            if(k>t2 && t3==0){
                t2=k;
                cout<<1;
            }
            else if(k==t1 && t3!=0){
                t3=k;
                cout<<1;
            }
            else if(k==t2 && t3==0){
                cout<<1;
            }
            else if(k<t2 && t3==0){
                t3=k;
                cout<<1;
            }
            else if(k==t3 && t3!=0){
                cout<<1;
            }
            else if(k<t2 && t3!=0){
                cout<<0;
            }

            else{
                cout<<1;
            }


        }
    }
    cout<<endl;
}

int main(){
    long long int test=0;
    long long int n=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        cin>>n;
        solve(n);
    }
    return 0;
}

