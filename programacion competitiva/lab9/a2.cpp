#include <bits/stdc++.h>
using namespace std;

int main(){
    int test=0;
    int n=0;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>n;
        if(n<5){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}

