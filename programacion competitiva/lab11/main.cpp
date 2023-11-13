#include <bits/stdc++.h>
using namespace std;
// se prepara el array inicial del patron
vector<long long int>prefixs(string s){// complejidad O(s.length)
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

long long int solve(string s1,string s2) {// complejidad O(s1.length+s2.length)
    vector<long long int> pf=prefixs(s2);
    long long int count=0;
    long long int i=0;
    long long int j=0;

    while(i<s1.length()){
        if(s1[i]==s2[j]){// si coinciden los caracteres se incrementa los indices i y j
            i++;
            j++;
        }
        if (j==s2.length()){// si se llega a cumplir el match completo
            count++; // agregamos a nuestro contador
            j=pf[j-1];
        }
        else if(i<s1.length() && s1[i]!=s2[j]) {//caso no coincidan
            if(j!=0){
                j=pf[j-1];
            }
            else{
                i++;
            }
        }
    }
    return count;
}

int main(){
    long long int n=0;
    string s1;
    getline(cin,s1);
    string s2;
    getline(cin,s2);
    cout<<solve(s1,s2); //complejidad O(s1.length+s2.length)

    return 0;
}
