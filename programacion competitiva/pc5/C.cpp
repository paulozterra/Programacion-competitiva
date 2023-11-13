#include <bits/stdc++.h>
using namespace std;
//se necesita dp? si fueran mas numeros de casos si es mas eficiente usar dp
int solve(string n){
    int count=0;
    int num=-1;
    int max=0;
    while(num!=0){
        for(int i=0;i<n.size();i++){
            if(n[i]-48>max){
                max=n[i]-48;
            }
        }
        num=stoi(n);
        n= to_string(num-max);
        count++;
        max=0;
    }
    return count-1;
}


int main(){

    string n;
    getline(cin,n);
    cout<<solve(n);
    return 0;
}