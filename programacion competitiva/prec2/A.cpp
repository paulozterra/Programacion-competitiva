#include <bits/stdc++.h>
using namespace std;

int raices(int matriz[0]){

}

int solve(int matriz[10][10],string num) {
    char s1 = num[0];
    int i1=s1-48;
    char s2 = num[1];
    int i2=s2-48;
    if (num.size() == 3) {
        char s3 = num[2];
        int i3=s3-48
    }


    return 1;
}
int main(){
    int matriz[10][10]{1,0,0,0,0,0,0,0,0,0,
                       1,1,1,1,1,1,1,1,1,1,
                       1,0,1,1,0,1,1,0,1,1,
                       0,0,0,1,0,0,1,0,0,1,
                       1,0,0,0,1,1,1,1,1,1,
                       1,0,0,0,0,1,1,0,1,1,
                       0,0,0,0,0,0,1,0,0,1,
                       1,0,0,0,0,0,0,1,1,1,
                       1,0,0,0,0,0,0,0,1,1,
                       0,0,0,0,0,0,0,0,0,1};

    int n{};
    cin>>n;
    cin.ignore();
    string k;
    for(int i=0;i<n;i++){
        getline(cin,k);
        if(k.size()==1){
            cout<<k[0];
        }
        else if(k=="200"){
            cout<<k;
        }
        else{
            cout<<solve(matriz, k);
        }

    }

    return 0;
}