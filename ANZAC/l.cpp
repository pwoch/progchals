#include <iostream>

using namespace std;

int col[20] = {0};

int main() {

    string s;
    int N, odd, byte, bit, even, use, last_even, last_odd;
    last_even = last_odd = 0;
    use = odd = even = 0;
    cin >>N;
    bool found = false;
    int par = 0;
    char c, tmp;
    for (int i=1; i<=N; i++) {
        par = 0;
        for (int j=0; j<8; j++) {
            cin >> c;
            //cout<<c;
            if (c == '1') {
                par++;
                col[j]++;
            }
        }
        //cout <<"\t"<< par%2;
        //cout <<endl;
        if (found) continue;
        if (par%2 == 0) {
            //par is even 
            last_even=i;
            if (odd > 1) {
                found=true;
                use=1;
                cout <<"Odd\n";
                cout <<"Byte "<<last_even<<" is broken\n";
            }
            even++;
            if (even > 1 && last_odd != 0) {
                found=true;
                use=0;
                cout <<"Even\n";
                cout <<"Byte "<<last_odd<<" is broken\n";
            }

        } else {
            //par is odd 
            last_odd=i;
            if (even > 1) {
                found=true;
                use=1;
                cout <<"Even\n";
                cout <<"Byte "<<last_odd<<" is broken\n";
            }
            odd++;
            if (odd > 1 && last_even != 0) {
                found=true;
                use=0;
                cout <<"Odd\n";
                cout <<"Byte "<<last_even<<" is broken\n";
            }
        }
    }
    for (int j=0; j<8; j++) {
        cin >> c;
        //cout <<j<<": "<< col[j]%2<<" "<<(c+use)%2<<endl;
        if (col[j]%2 != (c+use)%2) { 
            bit = j;
            cout <<"Bit "<< bit+1<<" is broken\n";
            return 0;
        }
    }
}


