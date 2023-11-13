#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>pub,vector<int>tem){
    int matriz[pub.size()];
    for(int i=0;i<pub.size();i++){
        matriz[i]=-1;
    }
    for(int i=0;i<tem.size();i++){
        int id=0;
        if(tem[i]>pub.size()){
            int flag=0;
            for(int j=0;j<pub.size();j++){
                if(pub[j]==tem[i]){
                    flag=1;
                    id=j;
                    break;
                }
            }
            if(flag==0){
                pub.insert(pub.begin(),tem[i]);
                int temp=pub[pub.size()-1];
                pub.pop_back();
                if(temp<pub.size()+1)
                    matriz[abs(1-temp)]=i+1;
            }
            else{
                if(pub[0]>tem[i]){
                    pub.insert(pub.begin(),tem[i]);
                    int temp=pub[pub.size()-1];
                    pub.pop_back();
                    if(temp<pub.size()+1)
                        matriz[abs(1-(temp-1))]=i+1;
                }
                else{
                    pub.insert(pub.begin(),tem[i]);
                    pub.erase(pub.begin(),pub.begin()+1);
                }
            }

        }
        else{

        }
    }
    return 0;
}



int main(){
    int test=0;
    int n=0;
    int m=0;
    int temp=0;
    cin>>test;
    vector<int>pub;
    vector<int>tem;
    for(int i=0;i<test;i++){
        cin>>n>>m;
        for(int k=0;k<n;k++){
            pub.push_back(n-k-1);
        }
        for(int j=0;j<m;j++){
            cin>>temp;
            tem.push_back(temp);
        }
        cout<<solve(pub,tem)<<endl;
        pub.clear();
        tem.clear();
    }
    return 0;
}

