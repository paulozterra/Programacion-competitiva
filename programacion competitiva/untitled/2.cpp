#include <bits/stdc++.h>
using namespace std;

void solve(string cad,string cad2,long long t,long long int q) {
    long long int temp=0;
    long long int b=0;
    string cadtemp=cad;
    string cadtemp2=cad2;

    long long int c1=0,w1=0,w2=0,w3=0,w4=0;
    vector<char>tempchar;
    for (int i = 0; i < q; i++) {
        cin>>c1;
        if(c1==1){
            long long int g=0;
            cin>>g;
            temp=0;
            b=1;
            cadtemp[g-1]='0';
            cadtemp2[g-1]='0';

        }
        else if(c1==2){
            char t1;
            char t2;
            cin>>w1>>w2>>w3>>w4;
            if(w1==1){
                t1=cad[w2-1];
                if(w3==1){
                    t2=cad[w4-1];
                    cad[w2-1]=t2;
                    cad[w4-1]=t1;
                }
                else{
                    t2=cad2[w4-1];
                    cad[w2-1]=t2;
                    cad2[w4-1]=t1;
                }
            }
            else{
                t1=cad2[w2-1];
                if(w3==1){
                    t2=cad[w4-1];
                    cad2[w2-1]=t2;
                    cad[w4-1]=t1;
                }
                else{
                    t2=cad2[w4-1];
                    cad2[w2-1]=t2;
                    cad2[w4-1]=t1;
                }
            }


        }
        else{
            long long int y=1;
            for(int i=0;i<cad.size();i++){
                if(cadtemp[i]!='0' && cadtemp2[i]!='0' && cadtemp[i]!=cadtemp2[i]){
                    y*=0;
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(y==1){
                cout<<"YES"<<endl;
            }

        }
        if(b==1 && temp<t){
            temp+=b;
        }
        else{
            cadtemp[i]=cad[i];
            cadtemp2[i]=cad2[i];
        }

    }
}

int main(){
    long long int test=0;
    cin>>test;
    string cad;
    string cad2;
    long long int t=0,q=0;
    for(long long int i=0;i<test;i++){
        cin.ignore();
        getline(cin,cad);
        getline(cin,cad2);
        cin>>t>>q;
        solve(cad,cad2,t,q);
    }
    return 0;
}

