#include <bits/stdc++.h>
using namespace std;

void solve(long long int n){
    char arr[n];
    long long int count=0;
    long long int result=0;
    vector<long long int>pos;
    for(long long int i=0;i<n;i++){ // O(n)
        cin>>arr[i]; // se ingresa los valores
        if(arr[i]=='*'){ // se verifica los caracteres de interes
            pos.push_back(i);// se pushean los indices
            count++; // se incrementa el contador donde tendremos finalmente la cantidad de "*" que tenemos en el arr
            }
    }
    if(count==1 || count==0){ // si solo existe un solo asterisco o no hay asteriscos
        cout<<0<<endl;
        return;
    }
    else{
        long long int m=count/2;
        long long int c=1;
        for(long long int li=m-1;li>=0;li--){ // hallamos las diferencias desde su limite inferior
            result+=abs(pos[m]-pos[li]-c);
            c++;
        }
        c=1;
        for(long long int ls=m+1;ls<pos.size();ls++){ // hallamos las diferencias desde su limite inferior
            result+=abs(pos[ls]-pos[m]-c);
            c++;
        }
        cout<<result<<endl;
    }
    pos.clear();
}

int main(){
    long long int test=0;
    cin>>test;
    long long int n=0;
    for(long long int i=0;i<test;i++){// O(test)
        cin>>n;
        solve(n); // O(n)
    }
    return 0;
}
//complejidad O(test*n)

