#include <bits/stdc++.h>
using namespace std;
//realizar busqueda binaria para obtener la raiz cuadrada
//O(log(n))
int solve(long long int n){
    long long int left = 1;
    long long int right = n;
    long long int result = 0;
    if(n <=1) return 0;
    while(left<=right) {
        long long int mid=left+(right-left)/2;
        if(mid==n/mid) return mid;
        if(mid<n/mid){
            left=mid+1;
            result=mid;
        }
        else
            right=mid-1;
    }
    return result;
}

int main(){
    long long int test=0;
    //long long int result;
    cin>>test;
    long long int n=0;
    for(long long int i=0;i<test;i++){
        cin>>n;
        //result=sqrt(n-1);
        cout<<solve(n)<<endl;
    }
    return 0;
}
