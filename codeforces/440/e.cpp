#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

#define MAX (int)1e5+10
#define x first
#define y second
#define MOD (int)1e9+7

using namespace std; 

typedef pair<int,int> p;

vector<p> v(MAX);
set<int> h;
set<int> r;

int main() {
  int n, tmp;
  cin >>n;
  for (int i=0; i<n; i++) {
    cin>>v[i].x>>v[i].y;
    h.insert(v[i].x);
    r.insert(v[i].y);
  }

  int res = 1; 
  for (int i=0; i<n; i++) {
    int mul = 1;
    cout<<v[i].x<<" "<<v[i].y<<endl;
    if (h.count(v[i].x)) {
      mul++;
      h.erase(h.find(v[i].x));
    }
    if (r.count(v[i].y)) {
      mul++;
      r.erase(r.find(v[i].y));
    }
    res = (res*mul)%(MOD);
  }
  cout<<res<<endl;
}
