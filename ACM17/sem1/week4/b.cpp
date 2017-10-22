#include <iostream>
#include <algorithm>

#define MAX 100000

using namespace std;

int tree[3*MAX+1];

int sign(int b) {
    if (b>0) return 1;
    else if (b<0) return -1;
    else return 0;
}

void update(int a, int val, int i = 1, int start = 1, int end = MAX) {
    if (start == end) { tree[i] = val; return;}
    int mid = (start + end) / 2;
    if (a <= mid) update(a, val, i * 2, start, mid);
    else update(a, val, i * 2 + 1, mid + 1, end);
    tree[i] = tree[i*2]*tree[i*2+1];
}

int query(int a, int b, int i = 1, int start = 1, int end = MAX) {
    if(start == a && end == b) return tree[i];
    int mid = (start + end) / 2;
    int answer = 1;
    if(a <= mid) answer *= query(a, min(b, mid), i * 2, start, mid);
    if(b > mid) answer *= query(max(a, mid + 1), b, i * 2 + 1, mid + 1, end);
    return answer;
}

int main() {
    int N, K, tmp, a, b, result;
    while ((cin>>N>>K).good()) {
        for (int i=1; i< 3*MAX+1;i++) tree[i]=1;
        for (int i=1; i<=N;i++) {
            cin>>tmp;
            update(i,sign(tmp)); 
        }
        char c;
        for (int i=1;i<=K;i++) {
            cin>>c>>a>>b;
            if (c == 'P') {
                result = query(a,b);
                if (result > 0) cout<<'+';
                else if (result < 0) cout<<'-';
                else cout<<'0';
            } else {
                update(a,sign(b));
            }
        }
        cout<<endl;
    }
    return 0;
}
