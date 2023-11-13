#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int test=0;
    long long int a=0,b=0,c=0;
    long long int l=0,r=0,m=0;
    long long int n=0;
    cin>>test;
    for(long long int i=0;i<test;i++){
        cin>>l>>r>>m;
        long long int di=l-r,ds=r-l;
        for(long long int j=l;j<r+1;j++){
            if(m<l){
                n=1;
                a=l;
                long long int res=abs(m-a*n);
                b=l;
                c=b+res;
                break;
            }
            else{
                long long int temp1=m/j;
                long long int temp2=(m/j)+1;
                long long int temp=0;
                if(abs(m-temp1*j)<abs(m-(temp2 *j))){
                    n=temp1;
                }
                else{
                    n=temp2;
                }
                a=j;
                temp = m-n*a;

                if((ds>=temp && di<=temp ) ){
                    b=l;
                    c=b-temp;
                    if(b<l || b>r || c<l || c>r){
                        b=r;
                        c=b-temp;
                    }
                    break;
                }

            }

        }

        cout<<a<<" "<<b<<" "<<c<<endl;


    }
    return 0;
}

