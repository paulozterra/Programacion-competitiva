#include <bits/stdc++.h>
using namespace std;

int main(){
    double  a=0,b=0,c=0;
    cin>>a>>b>>c;
    double r1=0,r2=0;
    r1= (-b+ sqrt(b*b-4*a*c))/(2*a);
    r2= (-b- sqrt(b*b-4*a*c))/(2*a);
    if(r1>r2){
        cout<<fixed << setprecision(15)<<r1<<endl;
        cout<<fixed << setprecision(15)<<r2<<endl;
    }
    else{
        cout<<fixed << setprecision(15)<<r2<<endl;
        cout<<fixed << setprecision(15)<<r1<<endl;
    }

    return 0;
}

