#include <bits/stdc++.h>
using namespace std;
double const pi=3.14159265358979323846;
struct point {
    double x,y;
    point(double _x,double _y){
        x=_x, y=_y;
    }
    point operator+(const point &oth){
        return point(x+oth.x,y+oth.y);
    }
    point operator-(const point &oth){
        return point(x-oth.x,y-oth.y);
    }


};
double distance(point p,point q){
    return sqrt(pow(p.x-q.x,2.0)+pow(p.y-q.y,2.0));
}
void calcule_area(int n){
    double x=0,y=0;
    string d;
    vector<point>v;
    long double result=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back(point(x,y));
    }
    for(int i=1;i<n;i++){
        point p = v[i-1];
        point q = v[i];
        result +=(p.x-q.x)*(p.y+q.y);
    }
    result+=(v[n-1].x-v[0].x)*(v[n-1].y+v[0].y);
    double val=0;
    for(int i=0;i<n-1;i++){
        point a=v[i];
        point b=v[i+1];
        val += (b.x-a.x)*(b.y+a.y);
    }
    point a=v[n-1];
    point b=v[0];
    val += (b.x-a.x)*(b.y+a.y);

    if(val<0){
        d="CCW";
    }
    else{
        d="CW";
    }
    cout<<d<<" "<< fixed << setprecision(1)<<abs(result/2.0)<<endl;
}


int main(){
    int n=1;
    while(cin>>n){
        if(n==0){
            break;
        }
        else{
            calcule_area(n);
        }

    }

    return 0;
}

