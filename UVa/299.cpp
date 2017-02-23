#include <iostream>

using namespace std;


int bubble(int a[],int n) {
    int c = 0, s = 1;
    for (int i = 0; i < n && s; i++) {
        s = 0;
        for (int j = n-1; j>i; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j],a[j-1]);
                c++;
                s = 1;
            }
        }
    }
    return c;
}

int main() {
    int N;
    int a[60];
    cin>>N;
    for (int i = 0; i < N; i++){
        int n;
        cin>>n;
        for (int j=0; j < n; j++) cin>>a[j];
        cout<<"Optimal train swapping takes "<<bubble(a,n)<<" swaps.\n";
    }
    return 0;
}

