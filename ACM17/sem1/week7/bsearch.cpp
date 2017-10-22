
int bsearch(int *a, int t, int lo, int hi) {
    int m = lo + (hi-lo)/2;
    if (lo > hi) return -1;
    if (a[m] == m) return m;
    else if (a[m] > c) return bsearch(a,t,lo,hi-1);
    else return bsearch(a,t,lo+1,hi);
}


