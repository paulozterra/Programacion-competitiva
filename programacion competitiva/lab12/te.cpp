#include <bits/stdc++.h>
using namespace std;
double const pi=3.14159265358979323846;
double const inf=10000000000000000.0;
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


int main() {
    int test=0;
    cin >> test;


    return 0;
}