#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point(double _x, double _y){
        x=_x, y=_y;
    }
    point operator+(const point& oth) {
        return point(x + oth.x, y + oth.y);
    }
    point operator-(const point& oth) {
        return point(x - oth.x, y - oth.y);
    }
};
bool cmp(const point& a, const point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
double ccw(const point& p1, const point& p2, const point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

vector<point> solve(int n) {
    vector<point> p;
    vector<point>ph;
    int l=0;
    p.reserve(n);

    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    vector<double> temp;
    for(int i=0;i<n;i++){
        temp.push_back(-1);
    }
    for(int i=1;i<n;i++){
        if(p[i].x<p[l].x){
            l=i;
        }
    }
    int pnt=l,q;
    do{
        q=(pnt+1)%n;
        for(int i=0;i<n;i++){
            if(ccw(p[pnt],p[i],p[q])<0){
                q=i;
                temp[pnt]=q;
                pnt=q;
            }
        }
    }while(pnt!=1);

    for(int i=0;i<n;i++){
        if(temp[i]!=-1){
            cout<<"( "<<p[i].x<<" , "<<p[i].y<<")\n ";
            p.push_back(point(p[i].x,p[i].y));
        }
    }

    return ph;
}

double area(const vector<point>& ph) {
    double result = 0.0;
    for (int i = 0; i < ph.size(); i++) {
        double x1 = ph[i].x;
        double y1 = ph[i].y;
        double x2 = ph[(i + 1) % ph.size()].x;
        double y2 = ph[(i + 1) % ph.size()].y;
        result += (x1 * y2 - x2 * y1);
    }
    cout << fixed << setprecision(1) << abs(result / 2.0) << endl;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<point> p = solve(n);
        area(p);
    }
    return 0;
}
