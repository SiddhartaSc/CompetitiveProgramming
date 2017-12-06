#include <iostream>
#include <iomanip>

using namespace std;

struct PT {
    double x , y;
    PT () {}
    PT ( double x , double y) : x(x) , y( y) {}
    PT ( const PT &p ) : x(p .x) , y(p .y) {}
    PT operator + ( const PT &p ) const { return PT (x+p .x , y+p.y ); }
    PT operator - ( const PT &p ) const { return PT (x -p .x , y -p.y ); }
    PT operator * ( double c) const { return PT (x*c , y *c ); }
    PT operator / ( double c) const { return PT (x/c , y /c ); }
};

double dot ( PT p , PT q) { return p.x *q.x+ p.y* q.y; }
double dist2 ( PT p , PT q) { return dot (p -q ,p - q); }
double cross ( PT p , PT q) { return p.x *q.y - p.y* q.x; }

PT ComputeLineIntersection ( PT a , PT b , PT c , PT d) {
    b=b -a; d=c - d; c=c -a ;
    return a + b * cross (c , d)/ cross (b , d);
}

PT arrpts[8];
long long nint;
PT inter;

int main()
{
    cin >> nint;

    cout << "INTERSECTING LINES OUTPUT" << endl;
    for(int i=0;i<nint;i++){
        for(int j=0;j<4;j++){
            cin >> arrpts[j].x;
            cin >> arrpts[j].y;
        }
        inter = ComputeLineIntersection(arrpts[0],arrpts[1],arrpts[2],arrpts[3]);
        //cout << inter.x << " " << inter.y << endl;
        if(inter.x != inter.x)
            cout << "LINE" << endl;
        if(inter.x-inter.y != inter.x-inter.y)
            cout << "NONE" << endl;
        else
            cout << "POINT " << setprecision(3) << inter.x << " " << inter.y << endl;
    }
    cout << "END OF OUTPUT";

    return 0;
}
