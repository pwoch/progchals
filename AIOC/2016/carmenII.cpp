#include <fstream>

using namespace std;
#define M 100010
int a[M];

int main() {

    ifstream in("wherein.txt");
    ofstream out("whereout.txt");
    int N, C, A, B,total;
    in >>N >>C;
    in >>A;
    B=A;
    for (int i = 1; i < C; i++) 
        in >>B;
    for (int i = 1; i < N; i++) 
        in >>a[i];

    int m1, m2;
    m1 = m2 = M*10;
    //Find the largest handicap you can start with when going from A to B and vica versa
    for (int k = 1; k <= B-A; k++) {
        m1 = min(a[A+k-1]-k,m1);
        m2 = min(a[B-k]-k,m1);
    }
    //out<<"m: "<<m1<<", "<<m2<<endl;
    int s1,e1,s2,e2;
    s1=e1=A;
    s2=e2=B;
    //Check if we can reach A for each city A+k between A and B 
    for (int k = 1,n=M*10; k <= m1 && k < B-A && n > 0; k++) {
        n = min(a[A+k-1],n-1);
        if (n > 0) e1++;
    }
    //Check if we can reach A for cities between 1 and A
    for (int k = 1,n=M*10; k <= m1 && A-k >= 1 && n > 0; k++) {
        n = min(a[A-k], n-1);
        if (n > 0) s1--;
    }
    //out<<s1<<" "<<e1<<endl;

    //check if we can reach B from cities between B and N
    for (int k = 1,n=M*10; k <= m2 && B+k <= N && n > 0; k++) {
        n = min(a[B+k-1],n-1);
        if (n > 0) e2++;
    }
    //Check if we can reach B for each city B-k between B and A
    for (int k = 1,n=M*10; k <= m2 && k < B-A && n > 0; k++) {
        n = min(a[B-k],n-1);
        if (n > 0) s2--;
    }
    //out<<s2<<" "<<e2<<endl;

    if (e1 >= s2) total = e2 - s1+1;
    else total = ((m1>=0)?e1-s1+1:0) + ((m2>=0)?e2-s2+1:0);
    out<<total<<endl;

    return 0;
}

