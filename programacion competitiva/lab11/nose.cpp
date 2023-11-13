#include <bits/stdc++.h>
using namespace std;

// se prepara el array inicial del patron
vector<long long int>prefixs(string s){ // complejidad O(s.length)
    vector<long long int>result(s.length());
    for(long long int i=1;i<s.length();i++){
        long long int temp=result[i-1];
        while(temp>0 && s[i]!=s[temp]){
            temp=result[temp-1];
        }
        if(s[i]==s[temp]) temp++;
        result[i]=temp;
    }
    return result;
}

void solve(string s1,string s2) { // complejidad O(s1.length+s2.length)
    vector<long long int> pf=prefixs(s2);
    vector<long long int>indexs;
    long long int i=0;
    long long int j=0;

    while(i<s1.length()){
        if(s1[i]==s2[j]){ // si coinciden los caracteres se incrementa los indices i y j
            i++;
            j++;
        }
        if (j==s2.length()){ // si se llega a cumplir el match completo
            indexs.push_back(i-s2.size()); // guardamos el indice en donde inicia el patron
            j=pf[j-1];
        }
        else if(i<s1.length() && s1[i]!=s2[j]) { //caso no coincidan
            if(j!=0){
                j=pf[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(indexs.size()>0){  // si el patron se repite
        for(int i=0;i<indexs.size();i++){
            cout<<indexs[i]<<" "; // imprimir indices
        }
        cout<<endl;

    }
    else{ // si el patron no se repite en ninguna ocacion imprimir " "
        cout<<" "<<endl;
    }
    return;

}

int main(){

    string p;
    string t;
    while(getline(cin,p)){
        getline(cin,t);
        solve(t,p); // complejidad O(s1.length+s2.length)
        p.clear();
        t.clear();
    }

    return 0;
}

