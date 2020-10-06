#include <iostream>
#include <cmath>
using namespace std;

bool calculate_value(long long x, long long n, long long k){
    long long value = x*((long long)pow(2,k)-1);
    return n==value;
}

void calculate_x_values(long long n){
    long double n_log = ceil(log2(n+1));
    for(long long x = 1; x<=n; x++){
        bool encountered = false;
        for(long long k=2; k<=n_log; k++){
            encountered = calculate_value(x,n,k);
            if(encountered){
                cout << x << endl;
            }
        }
        if(encountered){
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