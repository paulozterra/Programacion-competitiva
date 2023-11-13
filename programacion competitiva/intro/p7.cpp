#include <bits/stdc++.h>
using namespace std;



long long int fact(long long int num){
    long long int result=1;
    if(num>0) {
        for (long long int i = 0; i < num; i++) {
            result *= (i+1);
        }
    }

    else{
        return 1;
    }
    return result;
}
int main(){
    long long int n{};
    cin>>n;
    long long int result{};
    for(long long int i=1;i<n+1;i++){
        if(i==1){
            cout<<0<<endl;
        }
        else if(i==2){
            cout<<6<<endl;
        }
        else if(i==3){
            cout<<28<<endl;
        }
        else if(i==4){
            cout<<96<<endl;
        }
        else{
            result= 0*(fact(0))+(6*(i-1)/(fact(1)))+(16*(i-1)*(i-2)/(fact(2)))+(30*(i-1)*(i-2)*(i-3)/(fact(3)))+(12*(i-1)*(i-2)*(i-3)*(i-4)/(fact(4)));
            cout<<result<<endl;
        }

    }

    return 0;
}//
// Created by pauloz on 31/03/2023.
//

