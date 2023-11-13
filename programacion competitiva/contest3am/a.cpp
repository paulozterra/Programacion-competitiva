#include <bits/stdc++.h>
using namespace std;

int solve(int sum,int prod,int tam){
    if(sum==tam and prod ==1){
        return 0;
    }
    else{
        int count=0;
        while(sum<0 || prod!=1){
            sum=sum+2;
            prod=prod*-1;
            count++;
        }
        return min(count,tam);
    }

    return 0;
}

int main(){
    int test=0;
    cin>>test;
    int tam=0;
    int sum=0;
    int prod=1;
    int e=0;
    for(int i=0;i<test;i++){
        cin>>tam;
        for(int j=0;j<tam;j++){
            cin>>e;
            sum+=e;
            prod*=e;

        }
        cout<<solve(sum,prod,tam)<<endl;
        sum=0;
        prod=1;
    }
    return 0;
}

