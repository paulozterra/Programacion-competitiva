#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int g=0;
    cin>>g;
    long long int r=0;
    r=g%360;
    if(r==0){
        cout<<0<<endl;
    }
    else{
        if(r<0){
            r=r+360;
        }
        if(r%90>45){
            cout<<r/90 +1<<endl;
        }
        else{
            cout<<r/90<<endl;
        }

    }
    return 0;
}

