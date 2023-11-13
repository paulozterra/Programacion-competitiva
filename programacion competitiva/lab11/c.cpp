#include <bits/stdc++.h>
using namespace std;

vector<long long int>prefixs(string s){
    vector<long long int>result(s.length());
    for(long long int i=1;i<s.length();i++){
        long long int temp=result[i-1];
        while(temp>0 && s[i]!=s[temp]){
            temp=result[temp-1];
        }
        if(s[i]==s[temp]) temp++;
        result[i]=temp;
    }
    return result;
}

long long int solve(string s1,string s2) {
    vector<long long int> pf=prefixs(s2);
    long long int count=0;
    long long int i=0;
    long long int j=0;

    while(i<s1.length()){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        if (j==s2.length()){
            count++;
            j=pf[j-1];
        }
        else if(i<s1.length() && s1[i]!=s2[j]) {
            if(j!=0){
                j=pf[j-1];
            }
            else{
                i++;
            }
        }
    }
    return count;
}

int main(){
    long long int n=0;
    string s1;
    getline(cin,s1);
    string s2;
    getline(cin,s2);
    cout<<solve(s1,s2);

    return 0;
}

