#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 1e6;
const long long z = 131, MOD = 1e9+21;
long long Z[MAXN+1];

//precalcula las potencias de (z^i)%MOD (importante hacer antes de hacer rolling hashing)
void fillZ() {
  Z[0] = 1;
  for(int n = 1; n <= MAXN; ++n)
    Z[n] = z*Z[n-1]%MOD;
}

struct RollingHashing {
  vector<long long> H;

  //crea los hash del string s
  RollingHashing(string &S) {
    int N = S.length();
    H.resize(N+1);
    H[N] = 0;
    for(int i = N-1; i >= 0; --i)
      H[i] = (S[i] + z*H[i+1])%MOD;
  }

  //entrega el hash del string s desde el indice i de tama�o k
  long long hash(int i, int k) {
    long long ans = (H[i] - Z[k]*H[i+k]%MOD);
    return ans >= 0 ? ans : ans + MOD;
  }
};

int main(){
    fillZ();
    long long counter = 0;
    string s;
    long long k;
    cin >> k;
    cin >> s;
    long long s_size = s.size();
    RollingHashing s_rh(s);
    reverse(s.begin(), s.end());
    RollingHashing s_reversed_rh(s);
    for(long long i = 0; i <= s_size-k; i++){
        long long s_hash = s_rh.hash(i, k);
        long long reversed_hash = s_reversed_rh.hash(s_size-k-i,k);
        if(s_hash == reversed_hash){
            counter ++;
        }
    }
    cout << counter << "\n";
    return 0;
}