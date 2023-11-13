#include <bits/stdc++.h>
using namespace std;

void solve(int n,int k,int x){

    int cant=0;
    int cant2=0;
    if(k==x && k>1){
        cant=n/(k-1);
        n=n-cant*(k-1);
        if(n==1 && x==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            if(n==0){
                cout<<cant<<endl;
                for(int j=0;j<cant;j++){
                    cout<<k-1<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<cant+1<<endl;
                for(int j=0;j<cant;j++){
                    cout<<k-1<<" ";
                }
                cout<<n<<endl;
            }
        }
    }
    else{
        cant=n/k;
        n=n-cant*k;
        if(n==1 && x==1 || k==x==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            if(n==0){
                cout<<cant<<endl;
                for(int j=0;j<cant;j++){
                    cout<<k<<" ";
                }
                cout<<endl;
            }
            else{

                if(n!=x){
                    cout<<cant+1<<endl;
                    for(int j=0;j<cant;j++){
                        cout<<k<<" ";
                    }
                    cout<<n<<endl;

                }
                else{
                    cant2= n/(x-1);
                    n = n-cant2*(x-1);
                    if(n!=0){
                        cout<<cant+cant2+1<<endl;
                        for(int j=0;j<cant;j++){
                            cout<<k<<" ";
                        }
                        for(int j=0;j<cant2;j++){
                            cout<<x-1<<" ";
                        }
                        cout<<n<<endl;
                    }
                    else{
                        cout<<cant+cant2<<endl;
                        for(int j=0;j<cant;j++){
                            cout<<k<<" ";
                        }
                        for(int j=0;j<cant2;j++){
                            cout<<x-1<<" ";
                        }
                        cout<<endl;
                    }

                }
            }

        }
    }
}

int main(){
    int test=0;
    int n=0;
    int x=0;
    int k=0;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>n>>k>>x;
        solve(n,k,x);

    }

    return 0;
}

