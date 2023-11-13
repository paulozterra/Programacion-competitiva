#include <bits/stdc++.h>
using namespace std;

struct Sx{
    int index;
    string sx;
};

bool compare(const Sx& a, const Sx& b) {
    return a.sx < b.sx;
}

vector<int>build(string text) {
    int n=text.length();
    vector<Sx> suffix(n);
    for (int i=0;i<n;i++){
        suffix[i].index=i;
        suffix[i].sx=text.substr(i);
    }
    sort(suffix.begin(),suffix.end(),compare);
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i]=suffix[i].index;
        cout<<arr[i]<<endl;
    }
    return arr;
}

int main() {
    string text;
    getline(cin,text);
    vector<int>arr=build(text);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
