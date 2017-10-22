#include <iostream>

#define cost(x) (c1+c2*(x-1)*(x-1))

using namespace std;
int N, c1, c2;

20/3 = 7
20/14 = 2
//Solve to find the optimal group split when we have a set number ofgroups
int solve(int amount) {
    int size = ceil(N/amount);
    return a
    int size = ceil(N/amount);
    int remainder = N%amount;
    return amount*cost(size) + ((remainder==0) ? 0 : cost(remainder));
}



int main() {

    int i, lo=1, hi=0, m;
    char t;
    cin >>N >>c1 >>c2;
    for (i=0; i<N; i++) {
        cin >>t;
        if (t == '1') hi++; 
    }
    cout<<"lo "<<lo<<"\thi"<<hi<<endl;
    for (i=1;i<=N;i++) cout<<i<<" "<<solve(i)<<endl;
    while (lo < hi) {
        int m1 = lo+(hi-lo)/3, m2 = hi-(hi-lo)/3;
        int s1 = solve(m1), s2 = solve(m2);
        cout<<"m1: "<<m1<<"\tm2: "<<m2<<endl;
        if ((hi-lo)/3 == 0) {solve(lo)>solve(hi) ? lo++ : hi--; continue;}
        if (s1 < s2) lo=m1; 
        else if (s1 > s2) hi=m2;
        else lo=m1,hi=m2; 
    }
    cout<<solve(lo)<<endl;

    return 0;
}
