
#include <iostream>
#include <vector>
#include <cmath>

#define MAX 320010
#define dist(p,q) 
#define f first
#define y second

using namespace std;

typedef pair<int,int> p;
p dir[4] = {p(1,0), p(0,1), p(-1,0), p(0,-1)};
p adj[4] = {p(0,-1), p(0,1), p(-1,0), p(0,-1)};

p findPoint(long long);

int main() {
    long long a,b;
    while (cin >>a >>b) {
        p q = findPoint(a);
        p r = findPoint(b);
        cout<<abs(q.f-r.f)+abs(q.y-r.y)<<endl;
    }
}


p findPoint(long long n) {
    long long t,s,inc;
    p loc;
    
    s=sqrt(n);
    if (s%2==0) s--;
    loc = p(-(s/2),-(s/2));
    if (s*s==n) return loc;
    t = s*s;
    inc = s;
    //Find cell for a
    for (int i=0;i<4;i++) {
        loc = p(loc.f+adj[i].f, loc.y+adj[i].y);
        t++;
        if (t <= n && n<=t+inc) {
            //cout<<n <<" is between ["<< t<<", "<<t+inc<<"] ";
            //cout<<loc.f<<", "<<loc.y<<endl;
            for (int j=0; j<=inc; j++,t++) {
                if (t == n) return loc;
                loc = p(loc.f+dir[i].f, loc.y+dir[i].y);
            }
            break;
        } 
        loc = p(loc.f+dir[i].f*inc, loc.y+dir[i].y*inc);
        t += inc;
    }
    return p(0,0);
}




