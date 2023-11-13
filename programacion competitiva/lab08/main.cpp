#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int test=0;
    long long int a=0,b=0,c=0,d=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        int count=0;
        cin>>a>>b>>c>>d;
        if(a==1){
            count++;
        }
        if(b==1){
            count++;
        }
        if(c==1){
            count++;
        }
        if(d==1){
            count++;
        }
        if((((a*d)-(c*b)) == 0 )){
            cout<<0<<endl;
        }
        else if(count>1){
            cout<<1<<endl;
        }
        else if(max(a,c)%min(a,c)!=0 && max(d,b)%min(d,b)!=0 && (a!=0 && b!=0 && c!=0 && d!=0)){
            cout<<2<<endl;
        }
        else{
            cout<<1<<endl;
        }


    }
    return 0;
}
