#include <bits/stdc++.h>
using namespace std;

int main(){
    char inp{};
    char a[16];
    int x{};
    int y{};
    int asci{};
    int total{};

    for(int i=0;i<16;i++){
        cin>>inp;
        a[i]=inp;
    }

    for(int i=0;i<16;i++){
        if(a[i]!='.'){
            asci=a[i];
            if((asci-65)-i!=0){
                total+= abs(((asci-65)/4)-(i/4)) + abs(((asci-65)%4 )-i%4) ;
            }
        }

    }
    cout<<total;

    return 0;
}
