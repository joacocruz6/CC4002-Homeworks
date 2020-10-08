#include <iostream>
#include <cmath>
using namespace std;



void calculate_x_values(long long n){
    long double n_log = ceil(log2(n+1));
    for(long long k=2; k<=n_log; k++){
        long long divisor = (long long)pow(2,k) - 1;
        if(n%divisor == 0){
            long long x = n / divisor;
            cout<<x<<endl;
            break;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t){
        long long n;
        cin >> n;
        calculate_x_values(n);
        t--;
    }
    return 0;
}