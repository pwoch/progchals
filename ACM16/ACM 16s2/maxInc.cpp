
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, max = 0;
    cin>> n;
    int nums[n];
    int i;
    for( i = 0; i < n; i++) {
        cin>> nums[i];
    }
    
    int start = 0;
    
    int j;
    for( i = 1; i < n; i++) {
        if( nums[i] <= nums[i-1]) {//end of increasing subsequence
            if( i - start > max) {
                max = i - start;
            }
                start = i;
        } 
    }

    if( i - start > max) {
        max = i - start;
        start = i;
    }
    cout<< max<<endl;

    return 0;
}
