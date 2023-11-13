#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int test=0;
    long long int n=0;
    long long int a=0;
    long long int sum=0;
    long long int min=0;
    int flag=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        cin>>n;
        for(long long int j=0;j<n;j++){
            cin>>a;
            if(a<0){
                flag=1;
                a=a*-1;
            }
            else if(a==0 && flag==1){
                flag=1;
            }
            else{
                if(flag==1){
                    min++;
                }
                flag=0;
            }
            sum=sum+a;
        }
        if(flag==1){
            min++;
        }
        cout<<sum<<" "<<min<<endl;

        sum=0;
        min=0;
        flag=0;
    }
    return 0;
}

