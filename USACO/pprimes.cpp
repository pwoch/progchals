/*
ID: wochnow1 
LANG: C++
TASK: pprime
*/
#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>

#define MAX 10001

using namespace std;

vector<vector<int> > v(9);
int a[MAX] = {0};

int isPrime(long long n) {
    int r = (n!=1);
    int m = (int) sqrt(n);
    for (int i = 2; i <= m; i++) {
        if (!(a[i] || n%i)) {
            r = 0;
            break;
        }
    }
    return r;
}

int main() {
    a[0] = 1;
    a[1] = 1;
    for (int i = 0; i < MAX; i++) 
        if(!a[i]) 
            for(int j = 2*i; j < MAX; j+=i) a[j] = 1;

    ifstream in("pprime.in");
    ofstream out("pprime.out");

    int a, b;
    in>> a>> b;

    int t;
    long long q;
    for(int i = 1; i < 10; i++) {
        t = i;
        if (t > b) continue; 
        if (t >= a && isPrime(t)) v[0].push_back(t);
        t = i*10 + i;
        if (t > b) continue; 
        if (t >= a && isPrime(t)) v[1].push_back(t);
        for (int j = 0; j < 10; j++) {
            t = i*100 + j*10 + i;
            if (t > b) continue; 
            if (t >= a && isPrime(t)) v[2].push_back(t);
            t = i*1000 + j*100 + j*10 + i;
            if (t > b) continue; 
            if (t >= a && isPrime(t)) v[3].push_back(t);
            for (int k = 0; k < 10; k++) {
                t = i*10000 + j*1000 + k*100 + j*10 + i;
                if (t > b) continue; 
                if (t >= a && isPrime(t)) v[4].push_back(t);
                t = i*100000 + j*10000 + k*1000 + k*100 + j*10 + i;
                if (t > b) continue; 
                if (t >= a && isPrime(t)) v[5].push_back(t);
                for (int n = 0; n<10; n++) {
                    t = i*1000000 + j*100000 + k*10000 +n*1000 + k*100 + j*10 + i;
                    if (t > b) continue; 
                    if (t >= a && isPrime(t)) v[6].push_back(t);
                    t = i*10000000 + j*1000000 + k*100000 +n*10000 + n*1000+ k*100 + j*10 + i;
                    if (t > b) continue; 
                    if (t >= a && isPrime(t)) v[7].push_back(t);
                    /*for (int l = 0; l < 10 && i == 1; l++) {
                        t = i*100000000 + j*10000000 + k*1000000 +n*100000 + l*10000 + n*1000+ k*100 + j*10 + i;
                        if (t > b) continue; 
                        if (t >= a && isPrime(t)) v[8].push_back(t);
                    }*/
                }
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        int l = v[i].size();
        for (int j = 0; j < l; j++) {
            out <<v[i][j]<<endl;
        }
    }


    return 0;
}
