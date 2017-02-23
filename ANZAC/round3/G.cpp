
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int size;
    cin>> size;

    int seq[size];
    int sum[size];
    int sumP = 0;
    int min = 0;
    int i;
    for( i = 0; i <size; i++){
        cin>> seq[i];
        sumP = sumP + seq[i];
        sum[i] = sumP;
       
    }
    min = sum[0];
    for( i = 0; i < size; i++){
        if( i != size - 1 && min > sum[i]) min = sum[i]; 
        cout<< seq[i]<<"\t"<<sum[i]<<endl;
    }

    cout<< "smallest partial sum "<< min<< endl;

    int errors = 0;
    if( min < 0){
        errors++;
    }

    for(i = size -1; i > 0; i--){
        cout<< "lowest partial sum term for next cycle ";

        if( min < 0){
            if( seq[i] < min){
                min = min + seq[i];
        cout<< min<< " l "<< endl;
            } else {
                min = seq[i];
                cout<< min<< endl;
            }
        } else {
            if( min < seq[i]){
                min = min + seq[i];
                cout<< min<< endl;
            }
        }
        
        if( min < 0){
            errors++;
        }
    }

    cout<< size - errors<< endl;

    return 0;
}


