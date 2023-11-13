#include <bits/stdc++.h>
using namespace std;
int main() {
    pair<long int,long int> C{};

    long int n{};
    int x{};
    int y{};
    int max{};
    int min{};
    long int dist{};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if((x+y)%2==0){
            dist= (x + y )/2;
            if(x<y){
                C.first=x;
                C.second=abs(dist-y);
            }
            else{
                C.second=y;
                C.first=abs(dist-x);
            }
            cout<<C.first<<" "<<C.second<<endl;
        }
        else{
            cout<<"-1 -1"<<endl;
        }


    }

    return 0;
}

