#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x,y;
};

double dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool cmpX(Point a, Point b){ return a.x < b.x; }
bool cmpY(Point a, Point b){ return a.y < b.y; }

double brute(vector<Point>& P, int l, int r){
    double d = 1e18;
    for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
            d = min(d, dist(P[i],P[j]));
    return d;
}

double stripClosest(vector<Point>& strip, double d){
    sort(strip.begin(), strip.end(), cmpY);
    double minD = d;

    for(int i=0;i<strip.size();i++)
        for(int j=i+1;j<strip.size() && (strip[j].y-strip[i].y)<minD;j++)
            minD = min(minD, dist(strip[i],strip[j]));

    return minD;
}

double closest(vector<Point>& P, int l, int r){
    if(r-l<=3) return brute(P,l,r);

    int mid = (l+r)/2;
    double dl = closest(P,l,mid);
    double dr = closest(P,mid+1,r);

    double d = min(dl,dr);

    vector<Point> strip;
    double midx = P[mid].x;

    for(int i=l;i<=r;i++)
        if(abs(P[i].x - midx) < d)
            strip.push_back(P[i]);

    return min(d, stripClosest(strip,d));
}

int main(){
    vector<Point> P = {
        {9,3},{2,6},{15,3},{5,1},{1,2},{12,4},{7,2},{4,7},
        {16,5},{3,3},{10,5},{6,4},{14,6},{8,6},{11,1},{13,2}
    };

    sort(P.begin(), P.end(), cmpX);

    double ans = closest(P,0,P.size()-1);

    cout<<"Minimum distance = "<<ans;
}
