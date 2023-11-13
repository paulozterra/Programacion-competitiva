#include <bits/stdc++.h>
using namespace std;

long long int binary(long long tam,long long pos){
    long long int l=0;
    long long int r=tam;
    long long int m=0;
    while(l+1<r){
        m = (l+r)/2;
        if(m*(m+1)/2>=pos){
            r=m;
        }
        else{
            l=m;
        }
    }
    return r;

}

int main(){
    int test=0;
    cin>>test;
    int tam=0;
    int pos=0;
    for(int i=0;i<test;i++){
        cin>>tam>>pos;
        long long int b2=binary(tam,pos);
        long long int b1=pos-((b2-1)*b2/2)-1;
        char result[tam];
        for(long long int i=0;i<tam;i++){
            if(i!=b1 && i!=b2){
                result[i]='a';
            }
            else{
                result[i]='b';
            }
        }
        for(long long int i=tam-1;i>=0;i--){
            cout<<result[i];
        }
        cout<<endl;
    }
    return 0;
}
