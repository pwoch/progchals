#include <iostream>
#define MAX 100000
int a[MAX];

int main() {
    int N,end,tmp;
    std::cin>>N;
    for (int i=0;i<N;i++) a[i]=1;
    end=N;
    for (int i=0;i<N;i++) {
        std::cin>>tmp;
        a[tmp]=-1;
        for (int j=end;j>=0 && a[j]==-1;j--,end--) std::cout<<j<<" ";
        std::cout<<"\n";
    }
}
