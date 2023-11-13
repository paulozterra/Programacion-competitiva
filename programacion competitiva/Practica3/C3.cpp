#include <bits/stdc++.h>
using namespace std;

int sum(int m,int b){
    int result=0;
    result=m*(m+1)/2;

    return 0;
}

int solve(int m,int b){
    int r=0;
    if(2*m-1<=b){
        return 2*m-1;
    }
    else{
        sum(m,b);
    }
}

int main(){
    int n{};
    cin>>n;
    int m{};
    int b{};
    for(int i=0;i<n;i++){
        cin>>m>>b;
        if(b==1){
            cout<<1<<endl;
        }
        else{
            cout<<solve(m,b);
        }
    }
    return 0;
}
// caso1 : exacto o no excede= sum(m) < = b -> return sum(m)
// caso 2: excede
//m1=sum(m)   m2=sum(m-1) ambos suman todos los mensajes del triangulo
// if sum(m1)>b  busco la max suma partiendo m1 en 2 y buscando si es menor o mayor
// if sum(m1)<b
// if sum(m2)>b busco la max suma partiendo m2 en 2 y buscando si es menor o mayor
// if sum(m2)<b retornar m2 + m1