


#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin>> n;
    map<int,int> set;
    int homo = 0;
    int tmp = 0;
    int size = 0;
    int noHomo = 0;
    int noHetero = 0;
    int hetero = 0;
    char str[10];
    for( int i = 0; i< n; i++) {
        cin>> str;
        cin>> tmp;
        if( strcmp(str,"insert") == 0){
            set[tmp]++;
            size++;
            //if you have more than one occurrence the set is now homogeneous
            if( set[tmp] != 1) { 
                noHomo++;
                homo = 1;
            }
            //if size > set[tmp] then there are other numbers and the set is hetero 
            if( set[tmp] < size) {
                hetero = 1;
                if( set[tmp] == 1) {
                    noHetero++;
                }
            }

        } else {
            if( set[tmp] != 0) {
                set[tmp]--;
                size--;
                if( set[tmp] == 1) {
                    noHomo--;
                    if( noHomo == 0) {
                        homo = 0;
                    }
                } else if( set[tmp] == 0) {
                    noHetero--;
                    if( noHetero == 0) {
                        hetero = 0;
                    }
                } 
            }
        }
        
        if( homo && hetero) {
            printf("both\n");
        } else if (homo) {
            printf("homo\n");
        } else if( hetero) {
            printf("hetero\n");
        } else {
            printf("neither\n");
        }
    }
    return 0;
}
