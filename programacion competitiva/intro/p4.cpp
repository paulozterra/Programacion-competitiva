//
// Created by pauloz on 29/03/2023.
//

#include <iostream>
using namespace std;
int main(){
    long int count{};
    long int input{};
    long int n{};
    long int current{};
    cin>>n;
    cin>>input;
    current=input;
    for(int i=1;i<n;i++){
        cin>>input;
        if(input<=current){
            count+=current-input;
            input=current;
        }
        else{
            current=input;
        }
    }

    cout<<count;
    return 0;
}