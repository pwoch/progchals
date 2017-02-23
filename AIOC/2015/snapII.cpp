#include <fstream>

using namespace std;

#define M 100010

int a[2*M];
int p[M];

int main() {

    ifstream in("snapin.txt");
    ofstream out("snapout.txt");
    int N;
    int tmp;
    in >>N;
    for (int i = 0; i < 2*N; i++) {
        in >>a[i];
        p[a[i]] = i;
        //out<<a[i]<<"("<<p[a[i]]<<") ";
        
    }
    //out<<endl;

    int face, top, otop, total, next;
    total = 0;
    top = 0;
    otop = 1;
    face = -1;
    while (otop < 2*N) {
        //out<<"top, otop, face = "<<a[top]<<", "<<a[otop]<<", "<<face<<" at indices: "<<top<<", "<<otop<<", other pair p[top], p[otop] at: "<< p[a[top]]<<", "<<p[a[otop]]<<endl;

        next = (otop != 2*N) ? a[otop+1] : -1;
        if (face == a[top]) {
            //Matching top with face card
            //out<<"playing top: "<<a[top]<<endl;
            face = -1;
            total++;
            top = otop;
        } else if (face == a[otop]) {
            //Matching otop with face
            //out<<"playing otop: "<<a[otop]<<endl;
            face = -1;
            total++;
        } else if (a[top] == next) {
            //playing top since its partner is next
            //out<<"playing top, since its next: "<<a[top]<<endl;
            face = a[top];
            top = otop;
        } else if (a[otop] == next) {
            //playing otop since its partner is next
            //out<<"playing otop, since its next: "<<a[otop]<<endl;
            face = a[otop];
        } else {
            //Check if we've played the pair for top yet
            //and if we've played the pair for otop or if the pair for top is closer than otops pair
            if ((p[a[top]] != top) && (p[a[otop]] == otop || p[a[top]] < p[a[otop]])) {
                //play otop, since otop doesnt have a pair left 
                //or pair of top is closer to the front than otops
                //out<<"playing otop: "<<a[top]<<endl;
                face = a[otop];
            } else {
                //play top 
                //out<<"playing top: "<<a[otop]<<endl;
                face = a[top];
                top = otop;

            }
        }
        otop++;
    }
    //check the last remaining card
    if (a[top] == face) total++;
    out<< total<<endl;
    return 0;
}


