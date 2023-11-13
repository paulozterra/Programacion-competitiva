#include <bits/stdc++.h>

using namespace std;

int main(){
    string inicio;
    string fin;
    string resultado;
    string horaf;
    string horai;
    string minf;
    string mini;
    string segf;
    string segi;
    int hora{};
    int min{};
    int seg{};
    string result;

    getline(cin,inicio);
    getline(cin,fin);

    for(int i=0;i<7;i++){
        if(i<2){
            horaf+=fin[i];
            horai+=inicio[i];
        }
        else if(i>2 && i<5){
            minf+=fin[i];
            mini+=inicio[i];
        }
        else if(i>5){
            segf=fin[i];
            segi=inicio[i];
        }
    }

    hora=stoi(horaf)-stoi(horai);
    min=stoi(minf)-stoi(mini);
    seg=stoi(segf)-stoi(segi);
    if(hora<10){
        horaf+="0"+to_string(hora);
    }
    else{
        horaf=to_string(hora);
    }
    if(min<10){
        minf+="0"+to_string(min);
    }
    else{
        minf= to_string(min);
    }
    if(seg<10){
        segf="0"+to_string(seg);

    }
    else{
        segf=to_string(seg);

    }
    result= horaf+":"+minf+":"+segf;
    cout<<result;

    return 0;
}//
// Created by pauloz on 3/04/2023.
//

