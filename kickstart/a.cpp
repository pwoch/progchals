#include <iostream>
#define MAX (int)1e5

using namespace std;
int sieve[MAX] = {};

int gcd( int a, int b ) {
  if ( a==0 ) return b;
  return gcd( b%a, a );
}

int main() {
  for (int i=2; i<MAX; i++) {
    if (sieve[i] == 0) {
      for (int j=2*i; j<MAX; j+=i) {
        sieve[j] = 1;
      }
    }
  }
  sieve[1] = 1;
  int T, a, n, p;
  int y = 1;
  cin >>T;
  for (int t=1; t<=T; t++) {
    cin >>a >>n >>p;
    //cout<<a <<n <<p<<endl;
    //Find y = totient(p)
    if (sieve[p] == 0) {
      //p is prime
      y = p-1;
    } else {
      y=1;
      int i = 2;
      int l = p;
      int ct = 0;
      for (int i=2; l != 1; i++) {
        int prevPw = 0;
        int pw = 1;
        if (sieve[i]) continue;
        if (l%i) continue;
        //i is prime divisor of l
        while (l%i == 0) {
          prevPw = pw;
          pw *= i;
          l = l/i;
        }
        y *= (pw - prevPw); 
      }
    }
    //cout<<"Totient of "<<p <<" is "<< y<<endl;
    int fac = 1;
    //find fac = n! mod y

    for (int i=2; i<=n; i++) {
      fac = (fac*i) % y;
    }
    //find a^fac mod p 
    if (fac == 0) {
      cout<<"Case #"<<t<<": "<<((a%p)?"1":"0")<<endl;
    }
    else {
      int ans=1;
      while (fac != 0) {
        ans = (ans*a) % p;
        fac--;
      }
      cout<<"Case #"<<t<<": "<<ans<<endl;
    }
  }
}
