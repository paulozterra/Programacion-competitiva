//
// Created by pauloz on 1/07/2023.
//

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
    double distance(point oth = point(0,0)) const {
        return sqrt(pow(x-oth.x,2.0)+pow(y-oth.y,2.0));
    }

};
double rad_to_sexa(double rad){
    return rad*(180.0/pi);
}
double sexa_to_rad(double sexa){
    return sexa*(pi/180.0);
}
vector<double> solve(int cant){

    vector<double>result;
    double ang=0;
    double dist=0;
    double x=0;
    double y=0;
    double ang_init=90;
    for(int i=0;i<cant;i++){
        cin>>ang>>dist;
        ang_init+=ang;
        //double temp_ang=sexa_to_rad(abs(ang_init));
        x+=dist*cos(ang_init*pi/180.0);
        y+=dist*sin(ang_init*pi/180.0);
    }
    result.push_back(x);
    result.push_back(y);

    return result;
}


int main(){
    int test=0;
    int cant=0;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>cant;
        vector<double> p=solve(cant);
        cout<< fixed << setprecision(6)<<p[0]<<" "<<p[1]<<endl;
    }
    return 0;
}

