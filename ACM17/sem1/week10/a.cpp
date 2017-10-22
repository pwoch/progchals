#include <iostream>
using namespace std;


struct p{
    int x, y;
    
    p(int x, int y) : x(x), y(y) {
    }

};

double operator-(p a, p b) {
    return (double) (a.x*b.y-a.y*b.x);
};

p operator*(p a, p b) {
    return p(b.x - a.x, b.y - a.y);
};




int main() {
    int N;
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >>N;
    for (int i=0; i<N; i++) {
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        p a1 = p(x1, y1), b1 = p(x2, y2), a2 = p(x3, y3), b2 = p(x4, y4);
        p r = b1-a1, s=b2-a2;
        if (r*s==0) {
            if (p%q==0 && q%p==0) {

        int t = ((a1-a2)*s)/(r*s);
        int u = ((a2-a1)*r)/(s*r);
        
    }
}
