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

double distan(point p1,point p2,point p3){
    double A=-1*(p3.y-p2.y);
    double B=p3.x-p2.x;
    double C=(p3.y-p2.y)*p2.x - (p3.x-p2.x)*p2.y;
    double d= abs(A*p1.x+B*p1.y+C)/ sqrt(A*A + B*B);
    double px = (B*(B*p1.x-A*p1.y)-A*C)/(A*A + B*B);
    double py = (A*(-1.0*B*p1.x+A*p1.y)-B*C)/(A*A + B*B);
    if(max(p2.y,p3.y)>=py && py>=min(p2.y,p3.y) && max(p2.x,p3.x)>=px && px>=min(p2.x,p3.x)){
        return d;
    }
    double dist1= sqrt((p2.y-p1.y)*(p2.y-p1.y) +(p2.x-p1.x)*(p2.x-p1.x) );
    double dist2= sqrt((p3.y-p1.y)*(p3.y-p1.y) +(p3.x-p1.x)*(p3.x-p1.x) );
    return min(dist1,dist2);
}


void Radios(int test){
    for(int i=0;i<test;i++){
        int pol_in=0;
        int pol_ext=0;
        double xi=0,yi=0;
        double xe=0,ye=0;
        vector<point>points_in;
        vector<point>points_ext;

        cin>>pol_in;
        for(int j=0;j<pol_in;j++) {
            cin>>xi>>yi;
            points_in.push_back(point(xi, yi));
        }
        cin>>pol_ext;
        for(int j=0;j<pol_ext;j++){
            cin>>xe>>ye;
            points_ext.push_back(point(xe, ye));
        }
        double mind=inf;
        for(int j=0;j<pol_in;j++){
            for(int k=0;k<pol_ext;k++){
                point p1 =points_in[j];
                point p2 =points_ext[k];
                point p3 =points_ext[(k+1)%pol_ext];
                double dist=distan(p1,p2,p3);
                mind=min(mind,dist);
            }
        }
        cout<< fixed << setprecision(8)<<mind/2.0<<endl;
    }
}

int main() {
    int test=0;
    cin >> test;
    Radios(test);

    return 0;
}