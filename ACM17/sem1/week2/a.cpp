
#include <iostream>
#include <cmath>

using namespace std;

int pw(int b,int e) {
    if (e == 0) {
        return 1;
    } else {
        if (e%2) {
            return (b*pw(b,e-1))%10;
        } else {
            int n = pw(b,e/2);
            return (n*n)%10;
        }
    }
}

int main() {
    int n;
    cin >>n;
    cout<<pw(1378%10,n)<<endl;
    return 0;
}
