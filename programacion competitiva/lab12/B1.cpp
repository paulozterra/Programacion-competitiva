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
bool comp(const point& p,const point& q){
    if(p.x == q.x) return p.y < q.y;
    return p.x< q.x;
}

vector<point> solve(int n){
    double result=0;
    vector<point>p;
    for(int i=0;i<n;i++){
        double x=0,y=0;
        cin>>x>>y;
        p.push_back(point(x,y));
    }
    double ymin=p[0].y;
    double temp=0;
    for(int i=1;i<n;i++){
        if((p[i].y==ymin && p[i].x < p[temp].x) || p[i].y<ymin ){
            temp=i;
            ymin=p[i].y;
        }
    }
    point ptemp = p[0];
    p[0]=p[temp];
    p[temp]=ptemp;

    std::sort(p.begin()+1, p.end(),comp);
    int tempi=1;
    for(int i=1;i<n;i++){
        double val = (p[i].y-p[0].y)*(p[i+1].x-p[i].x)-(p[i].x-p[0].x)*(p[i+1].y-p[i].y);
        while(i<n-1 && val==0){
            i++;
        }
        p[tempi]=p[i];
        tempi++;
    }

    vector<point>p_hull;
    p_hull.push_back(p[0]);
    p_hull.push_back(p[1]);
    p_hull.push_back(p[2]);

    for(int i=3;i<tempi;i++){
        double value = (p_hull[p_hull.size()-1].y-p_hull[p_hull.size()-2].y)*(p_hull[i].x-p_hull[p_hull.size()-1].x)-(p_hull[p_hull.size()-1].x-p_hull[p_hull.size()-2].x)*(p_hull[i].y-p_hull[p_hull.size()-1].y);
        if(value>0){
            p_hull.pop_back();
        }
        else{
            p_hull.push_back(p[i]);
        }
    }
    return p_hull;
}

void area(vector<point>p){
    double result=0;
    for(int i=1;i<p.size();i++){
        point a = p[i-1];
        point b = p[i];
        result +=(a.x*b.x)-(a.y*b.y);
    }
    result+=(p[p.size()-1].x*p[0].x)-(p[p.size()-1].y*p[0].y);
    cout<< fixed << setprecision(1)<<abs(result/2.0)<<endl;
}

int main(){
    int n=1;
    while(cin>>n){
        if(n==0){
            break;
        }
        else{
            vector<point> p =solve(n);
            area(p);
        }

    }
    return 0;
}

