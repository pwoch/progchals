#include <fstream>

using namespace std;

int a[100000];

int main() {
    
    ifstream in("frogin.txt");
    ofstream out("frogout.txt");

    int N, K;
    in >>N >>K;
    for (int n = 0; n < N; n++) in>>a[n];

    int diff = N-a[0];
    int total = abs(diff);
    for (int i = 1; i < N; i++) {
        //Adjust first pad
        




    
