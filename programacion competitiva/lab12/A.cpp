#include <bits/stdc++.h>
using namespace std;

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

double area(point p1,point p2,point p3){
    double result=0;
    result= 0.5*abs(p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y));
    return result;
}


int main(){
    int n=0;
    double x1=0.0,x2=0.0,x3=0.0;
    double y1=0.0,y2=0.0,y3=0.0;
    cin>>x1>>y1;
    point p1(x1/1.0,y1/1.0);
    cin>>x2>>y2;
    point p2(x2/1.0,y2/1.0);
    cin>>x3>>y3;
    point p3(x3/1.0,y3/1.0);
    double A=area(p1,p2,p3);
    int cont=0;
    cin>>n;
    for(int i=0;i<n;i++){
        double sum=0.0;
        double x=0.0,y=0.0;
        cin>>x>>y;
        point p4(x,y);
        double a1=area(p4,p1,p2)*1.0;
        double a2=area(p4,p2, p3)*1.0;
        double a3=area(p4,p1,p3)*1.0;
        if(a1+a2+a3==A){
            cont++;
        }
    }
    cout << fixed << setprecision(1)<<A<<endl;
    cout<<cont<<endl;


    return 0;
}

