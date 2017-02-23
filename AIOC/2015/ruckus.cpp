
#include <fstream>


#define MAX 100011 

using namespace std;

struct child{
    int l, r;
};

child a[MAX];
int visited[MAX];

int main() {
    ifstream in("ruckusin.txt");
    ofstream out("ruckusout.txt");

    int N, L, lollies, M;
    in >>N >>L >>lollies >>M;
    int u, v;
    for (int i=0; i < MAX; i++) {
        visited[i] = 0;
        a[i].r = -1;
        a[i].l = -1;
    }
    for (int i=0; i < L; i++) {
        in >>u >>v;
        a[u].r = v;
        a[v].l = u;
    }

    int teams = 0;
    //Find all groups that are not loops
    for (int i=1, len=0; i <= N; i++, len=0) {
        //Start at the right hand end of each line
        if (a[i].r != -1) continue;
        v = i;
        while (v!=-1) {
            visited[v] = 1;
            len++;
            v = a[v].l;
        }
        if (len < M) continue;
        if (lollies > 0) {
            teams += min(len/M, lollies+1);
            lollies -= min(len/M - 1, lollies);
        } else {
            teams++;
        }
    }
    //Find all groups that are loops
    for (int i = 1, len=0; i <= N; i++, len=0) {
        if (visited[i]) continue;
        v = i;
        do {
            visited[v] = 1;
            v = a[v].l;
            len++;
        } while (v != i);

        if (len < M) continue;
        if (lollies > 1) {
            lollies--; //Make it into a line
            teams += min(len/M, lollies+1);
            lollies -= min(len/M - 1, lollies);
        } else {
            teams++;
        }
    }
    out<<teams<<endl;
    return 0;
}

