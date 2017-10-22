#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int s[100010];

int hash[3] = {0};

int main() {
    int N=0, tmp, pF, f, sum=0, i=0, z=0, ans;
    pF = 0;
    f = 0;
    char t;
    char a[500010];
    scanf("%s\n", a);
    N = strlen(a);
    
    int j;
    for (i=N-1; i >= 0; i--) {
        j = N-i-1;
        tmp = (int)(a[i]-'0');
        s[j] = (tmp%3 || tmp==0) ? tmp%3 : 3;
        printf("%d\n", s[j]);
        if (s[j]==0) z = 1;
        sum += s[j]%3;
        hash[s[j]%3]++;
        if (s[j] != 0) {
            pF = f;
            f = j;
            printf("f=%d pF=%d\n",f, pF);
        }
    }
    N=i-1;

    if (sum == 1) {
        if (hash[1] > 1) {
            //More than one ones
            //Delete the first one from the back
            ans=1;
        } else if (hash[1] == 1) {
            //One one
            switch(f-pF) {
                case(0) : 
                    //Input only consists of one number
                    //Impossibru
                    ans=-1;
                    break;
                case(1) :
                    //there are two nonzero leading entries, so we can remove a one no worries
                    ans=1;
                    break;
                default :
                    if (s[f] == 1) {
                        if (hash[2]>1) {
                            //delete the first two twos you find
                            ans = 2;
                        } else {
                            //delete everything up to pF
                            ans = f-pF;
                        }
                    else {
                        //delete the first one you find
                        ans = 1;
                    }
                    break;
            }
        } else {
            //No ones
            if (hash[2] < 2) {
                //Not enough twos
                if (z) {
                    //Delete everything except for one 0 
                    ans = N-1;
                } else {
                    //Impossibru
                    ans = -1;
                }
            } else if ( hash[2]==2) {
                if (s[f] == 2 || s[pF] == 2) {
                    //Impossibru
                    ans = -1;
                }
            } else {
                //Delete the first two twos you can find
                ans=2;
            }
        }
    } else if (sum == 2) {
        if (hash[2] > 1) {
            //More than one two
            //Delete the first one from the back
            ans=1;
        } else if (hash[2] == 1) {
            //One two 
            switch(f-pF) {
                case(0) : 
                    //Input only consists of one number
                    //Impossibru
                    ans=-1;
                    break;
                case(1) :
                    //there are two nonzero leading entries, so we can remove a two no worries
                    ans=1;
                    break;
                default :
                    if (s[f] == 1) {
                        if (hash[2]>1) {
                            //delete the first two twos you find
                            ans = 2;
                        } else {
                            //delete everything up to pF
                            ans = f-pF;
                        }
                    else {
                        //delete the first two you find
                        ans = 1;
                    }
                    break;
            }
        } else {
            //No twos 
            if (hash[2] < 2) {
                //Not enough twos
                if (z) {
                    //Delete everything except for one 0 
                    ans = N-1;
                } else {
                    //Impossibru
                    ans = -1;
                }
            } else if ( hash[2]==2) {
                if (s[f] == 2 || s[pF] == 2) {
                    //Impossibru
                    ans = -1;
                }
            } else {
                //Delete the first two ones you can find
                ans=2;
            }
        }
    } else {
        ans = 0;
    }
    printf("%d\n", ans);

    return 0;
}

