#include <iostream>
#include <cmath>
using namespace std;
const long long int mod = 1e9 + 7;

long long int pot(long long int x, long long int y) {
    long long int result=0;
    if(y==0) return 1;
    long long int r=((pot(x,y/2))%mod);
    result=(r*r)%mod;
    if(y%2==1) result=(result*x)%mod;
    return result;
}

int main() {
    long long int n = 0;
    std::cin >> n;

    long long int r1 = 1;
    long long int r21 = 1;
    long long int r22 = 1;
    long long int rtemp = 1;
    long long int r3 = 1;

    for (long long int i = 0; i < n; i++) {
        long long int x = 0;
        long long int k = 0;
        std::cin >> x >> k;
        //cantidad de divisores obtenidos ejem: 720=2^4 * 3^2 * 5
        // cantidad de divisores: (exp1 + 1) * (exp2 + 1) * (exp3 + 1) = 30 ----> exp1 =4 , exp2=2 , exp3= 1
        r1 = (r1 * (k + 1)) % mod; // cantidad de divisores
        //sumatoria de divisores dada por
        //      (exp1+1)             (exp2+1)
        // (base1       -1 )   (base2       -1 )                -----> r21
        // (-------------- ) * (-------------- )* sucesivamente
        // (   base1 -1    )   (  base2 -1     )                ------>r22
        r21 = (r21 * (pot(x, k + 1) - 1)) % mod;
        r22 = (r22 * (x - 1)) % mod;
        if(k%2==0){
            rtemp*=pot(x,k*(k)/2)% mod;

        }
        else{
            rtemp*=pot(x,k*(k+1)/2)% mod;
        }
    }

    std::cout << r1 << " ";
    std::cout << (r21 * pot(r22, mod - 2)) % mod << " "; //inversa multiplicativa modular
    cout<<rtemp;

    return 0;
}