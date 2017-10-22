#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    int N;
    getline(cin, s1);
    getline(cin, s2);
    string s;
    cin >>N >> s;
    int n1, n2;
    n1 = n2 = 0;
    for (int i=0; i<N; i++) {
        switch(s[i]) {
            case('H') :
                ((i+1)%2) ? n1++ : n2++; 
                break;
            case('D') :
                ((i+1)%2) ? n1+=2 : n2+=2;
                break;
            case('O') :
                (i%2) ? n1++ : n2++;
                break;
        }
        if (n1 >= 7 || n2 >= 7) break;
    }

    n1 = min(n1,7);
    n2 = min(n2,7);
    cout<<s1<<" "<<n1<<" "<<s2<<" "<<n2<<". ";
    if (n1 == 7 || n2 == 7) {
        cout<< ((n1 == 7)?s1:s2) << " has won."<<endl;
        return 0;
    } else {
        if (n1 == n2) cout<<"All square."<<endl;
        else cout<< ((n1>n2)?s1:s2) << " is winning."<<endl;

    }


return 0;
}
