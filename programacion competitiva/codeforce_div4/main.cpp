#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>mi, vector<string>lib){
    long long int max1=1000000;
    long long int c1=0;
    long long int max2=1000000;
    long long int c2=0;
    long long int max12=1000000;
    long long int c12=0;
    for(int i=0;i<mi.size();i++){
        if(lib[i]=="11"){
            c12=mi[i];
            if(c12<max12){
                max12=c12;
            }
        }
        if(lib[i][0]=='1'){
            c1=mi[i];
            if(c1<max1){
                max1=c1;
            }
        }
        if(lib[i][1]=='1'){
            c2=mi[i];
            if(c2<max2){
                max2=c2;
            }
        }
    }
    if(max1==1000000 || max2==1000000){
        return -1;
    }
    else if(max1+max2<max12){
        return max1+max2;
    }
    else{
        return max12;
    }

}


int main(){
    int t=0;
    cin>>t;
    vector<int>mi;
    vector<string>lib;
    long long int n=0;
    for(long long int i=0;i<t;i++){
        cin>>n;
        long long int min=0;
        string val;
        for(long long int j=0;j<n;j++){
            cin>>min;
            cin.ignore();
            getline(cin,val);
            mi.push_back(min);
            lib.push_back(val);
        }
        cout<<solve(mi,lib)<<endl;
        mi.clear();
        lib.clear();
    }
    return 0;
}