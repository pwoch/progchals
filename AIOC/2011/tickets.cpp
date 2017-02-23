
#include <fstream>

using namespace std;

#define MAX 101000

//c[i] is the cheapest option for day i
int c[MAX];
//nxt[i] is the next day after or at day i for which we need to buy a ticket
int nxt[MAX];

//t1, l1 is cost and length of ticket1 and same for t2, l2
int t1, l1, t2, l2, N, mx;

ifstream in ("ticketin.txt");
ofstream out ("ticketout.txt");


//Recursive version 

int f(int day) {
    if ( day > mx) {
        return 0;
    } 
    day = nxt[day];
    if ( c[day] == -1) {
        int tkt1 = t1 + f(day+l1);
        int tkt2 = t2 + f(day+l2);
        c[day] = min(tkt1, tkt2);
    }
    return c[day];
}


int main() {

    in >>t1 >>l1 >>t2 >>l2 >>N;
    mx = 0;
    for (int tmp, i = 0; in >>tmp;) {
        while ( i <= tmp) {
            nxt[i++] = tmp;
        }
        mx = tmp;
    }
    for (int i = 0; i < MAX; i++) c[i] = -1;
    out<< f(1)<<endl;

    return 0;
}


// Iterative version
/*
   int main() {

   in >>t1 >>l1 >>t2 >>l2 >>N;
   mx = 0;
   for (int tmp, i = 0; in >>tmp;) {
   while ( i <= tmp) {
   nxt[i++] = tmp;
   }
   mx = tmp;
   }
   for (int i = 0; i < MAX; i++) c[i] = 0;
   for (int j = mx; j > 0; j--) {
   int day = nxt[j];
   c[j] = min(t1 + c[day+l1], t2 + c[day+l2]);
//out << "day: "<< j <<" costs: "<< c[j]<<endl;
}
out << c[1]<<endl;
return 0;
}
 */


