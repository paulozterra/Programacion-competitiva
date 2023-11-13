#include <bits/stdc++.h>
using namespace std;
int main() {
    string horai;
    string horaf;

    getline(cin,horai);
    getline(cin,horaf);

    if(horai==horaf){
        cout<<"24:00:00";
    }
    else{
        string hf;
        hf=hf+horaf[0]+horaf[1];
        string hi;
        hi=hi+horai[0]+horai[1];
        string mf;
        mf=mf+horaf[3]+horaf[4];
        string mi;
        mi=mi+horai[3]+horai[4];
        string sf;
        sf=sf+horaf[6]+horaf[7];
        string si;
        si=si+horai[6]+horai[7];


        int t1{};
        t1=(stoi(sf)-stoi(si));
        int t2{};
        int t3{};
        int b{};
        b=t1<0;
        t2=(stoi(mf)-stoi(mi)-1*b);
        t1 = abs(60*b+t1);
        int c{};
        c=t2<0;
        t3=(stoi(hf)- stoi(hi)-1*c);
        t2=abs(60*c+t2);
        int d{};
        d=t3<0;
        t3= abs(24*d+t3);

        hf= to_string(t3);
        mf = to_string(t2);
        sf = to_string(t1);
        if(hf.length()!=2){
            hf="0"+hf;
        }
        if(mf.length()!=2){
            mf="0"+mf;
        }
        if(sf.length()!=2){
            sf="0"+sf;
        }
        cout<<hf<<":"<<mf<<":"<<sf;

    }

    return 0;
}
