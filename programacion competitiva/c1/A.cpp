#include <bits/stdc++.h>
using namespace std;
int main() {
    long int n{};
    set<long int>s;
    long int m{};
    long int t1{};
    long int t2{};

    cin>>n;
    long int v[n];

    for(int i=0;i<n;i++){
        cin>>m;
        s.insert(m);
    }
    int ca=0;
    for(auto j:s){
        v[ca]=j;
        ca++;
    }
    int c{};

    for(int k=0;k<n-1;k++){
        if(v[k+1]-v[k]==1){
            c++;
            if(c>1){
                v[k]=-1;
            }

        }
        else{
            c=0;
        }
    }
    int count=0;
    for(int w=0;w<n-1;w++){
        if(v[w]!=-1){
            if(v[w+1]==-1){
                cout<<v[w];
            }
            else{
                cout<<v[w]<<" ";
            }

            count=0;
        }
        else{
            if(count==0){
                cout<<"-";
            }
            count++;
        }
    }
    cout<<v[n-1];

    return 0;
}
