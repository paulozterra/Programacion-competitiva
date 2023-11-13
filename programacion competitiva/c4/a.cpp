#include <bits/stdc++.h>
using namespace std;

void solve(long long int n){
    long long int t3=0;
    long long int t5=0;
    if(n%3==0){
        t5=n;
    }
    else{
        while(t3+t5<=n){
            t3+=5;
            t5=n-t3;
            if(t5%3==0){
                break;
            }
        }
        if(t5%3!=0 || t3%5!=0 || n<3 || t3+abs(t5)!=n){
            cout<<-1<<endl;
            return;
        }
    }

    for(long long int i=0;i<n;i++){   //O(n)
        if(i<t5){
            cout<<5;
        }
        else{
            cout<<3;
        }
    }
    cout<<"\n";

}



int main(){
    long long int t=0;
    long long int n=0;
    cin>>t;
    while(t--){
        cin>>n;
        solve(n);
    }

    return 0;
}