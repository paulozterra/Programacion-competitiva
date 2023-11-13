#include <bits/stdc++.h>
using namespace std;

int* createvpi(const string &t){
    int m=t.size();
    int*pi=new int[m+1];
    if(0<=m) pi[0]=0;
    if(1<=m) pi[1]=0;
    for(int i=2;i<=m;i++){
        for(int j=pi[i-1];;j=pi[j]){
            if(t[j]==t[i-1]){
                pi[i] = j+1;
                break;
            }
            if(j==0){
                pi[i] =0;
                break;
            }
        }
    }
    return pi;
}

int stringmatch(const string &s,const string &t){

    int i=0;
    int j=0;
    int n=s.size();
    int m=t.size();
    int *pi=createvpi(t);
    while(j<m){
        while(i != -1 && (i== n || s[i] != t[j]))
            i = pi[i];

        i++;
        j++;

        if(i == m){
            cout << j - m << " ";
        }
    }
    delete[]pi;
    return -1;
}
int main() {
    std::string pattern, text;

    while (std::getline(std::cin, pattern)) {
        std::getline(std::cin, text);

        int position = stringmatch(text, pattern);

        if (position != -1) {
            std::cout << position << " ";
        }

        while (position != -1) {
            position = stringmatch(text.substr(position + 1), pattern);
            if (position != -1) {
                std::cout << position << " ";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}

