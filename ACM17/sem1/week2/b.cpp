#include <iostream>

#define S 317
#define MAX S*S 


//p[n] stores the smallest prime factor of n or 1 if n is prime
int p[MAX];

int main() {
    for (int i=1; i<MAX;i++) p[i]=1;
    for (int i=2; i<S; i++) 
        if (p[i] == 1)  // why are you testing equality with 1???
            for (long long j=i*i; j<MAX; j+=i)  
                p[j] = (p[j]==1) ? i : p[j];

    int n;
    while (std::cin >>n) {
        std::cout<<"1";
        //special case if n is 1
        if (n!=1) {
            //Keep dividing n by its prime factors in increasing size, until you get to the last factor
            while (p[n]>1) {
                std::cout<<" x "<<p[n];
                n=n/p[n];
            }
            std::cout<<" x "<<n;
        }
        std::cout<<std::endl;
    }
    return 0;
}



