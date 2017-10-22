#include <iostream>
#include <vector>

using namespace std;

int cmp(int a, int b) {
    if (a<b) return -1;
    if (a>b) return 1;
    return 0;
}
vector<int> prefix;

//Builds a magical prefix array for s
void computePrefixTable(string &s) {
    int m = s.length();
    prefix.resize(m);
    prefix[0] = -1;
    int k = -1;
    //k denotes the end index of the largest prefix that is also a suffix of s[0..(q-1)] 
    for (int q=0; q<m; q++) {
        //not so hard part of the algo
        //if the next character s[q] doesnt match the char after current largest prefix
        //continue to check if it matches the character after the largest prefix of the current prefix 
        while (k > -1 and s[k+1] != s[q]) {
            k = prefix[k];
        }
        //if the next character is also after the largest prefix 
        if (s[k+1] == s[q]) {
            k = k+1;
        }
        prefix[q] = k;
    }
}

int stringMatch(string a, string b) {
    int n = a.length();
    int m = b.length();
    computePrefixTable(a);
    //number of characters matched  
    int q = 0;
    for (int i=0; i<n; i++) {
        while (q > 0 && b[q] != a[i]) {
            q = prefix[q];
        }
        if (b[q] == a[i]) q = q+1;
        if (q+1 == m) return 1;
    }
    return 0;
}

int main() {
    int T, N;
    vector<char> v;
    string range, check;
    int newMate, oldMate;

    cin >>T;
    for (int t=0; t<T; t++) {
        cin >>N;
        for (int n=0; n<N; n++) {
            cin >>newMate;
            if (n != 0) {
                switch (cmp(newMate, oldMate)) {
                    case (1) :
                        range.push_back('G');
                        break;
                    case (0) :
                        range.push_back('E');
                        break;
                    case (-1):
                        range.push_back('L');
                        break;
                }
            }
            oldMate = newMate;
        }
        cin >>check;
        cout <<(stringMatch(range, check)?"YES\n":"NO\n");
    }

}
