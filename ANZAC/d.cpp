#include <iostream>

using namespace std;

int indxx(char c) {
    if ('A' <= c && c <= 'Z') return c -'A';
    return c - 'a';
}
int f[256] = {0};
int main() {
    string s;
    while (cin >>s) {
        for (int i=0; i<s.size(); i++) {
            int n = indxx(s[i]);
            if (n < 0 || n >= 26) continue;
            f[n]++;
        }
    }

    for (int i=0; i<26; i++) {
        cout <<(char) ('A'+i) << " | ";
        for (int j=0; j<f[i]; j++) cout<<"*";
        cout <<endl;
    }

}

