//
// Created by pauloz on 29/03/2023.
//

#include <iostream>
using namespace std;
int main() {
    string cad;
    getline(cin,cad);
    long int cont{};
    char current=cad[0];
    long int c_max=0;
    for(int i=0;i<cad.size();i++){
        if(cad[i]==current){
            cont++;
        }
        else{
            if(c_max<cont){
                c_max=cont;
            }
            current=cad[i];
            cont=1;
        }
    }
    if(c_max<cont){
        c_max=cont;
    }
    cout<<c_max;
    return 0;
}

