#include <bits/stdc++.h>
using namespace std;


int main(){
    long long int test=0;
    cin>>test;
    long long int  n=0;
    vector<long long int> arr;
    vector<long long int>temp;
    for(int i=0;i<test;i++){
        cin>>n;
        arr.push_back(n);
    }
    temp=arr;
    std::sort(temp.begin(), temp.end());
    

    return 0;
}

