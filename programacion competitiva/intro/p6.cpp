//
// Created by pauloz on 30/03/2023.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t{};
    long long int x{};
    long long int y{};
    cin>>t;
    long long int cad[t];
    long long int max{};
    long long int num{};

    for(long int i=0;i<t;i++){
        cin>>y>>x;
        if(x<y){
            max=y;
        }
        else{
            max=x;
        }
        num=max*max-(max-1);

        if(max%2==0){
            num= num +(y-x);
        }
        else{
            num= num -(y-x);
        }
        cad[i]=num;
    }
    for(long int j=0;j<t;j++){
        cout<<cad[j]<<endl;
    }

    return 0;
}