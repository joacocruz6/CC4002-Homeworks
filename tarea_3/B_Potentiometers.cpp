#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct FT {
	vector<long long> vec;

	FT(int n) {
		vec.assign(n, 0);
	}

	long long query(int i) {
		long long sum = 0;
	  	for (; i; i -= (i & (-i))) sum += vec[i];
	  	return sum;
	}

	void update(int i, long long x) {
	  	for (; i < vec.size(); i += (i & (-i))) vec[i] += x;
	}
};
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int N;
    cin >> N;
    int case_number = 1;
    while(N){
        FT FenwickTree(N+1);
        for(int i=0; i<N; i++){
            int x_i;
            cin >> x_i;
            FenwickTree.update(i+1,x_i);
        }
        cout << "Case "<<case_number<<":\n"; 
        string query;
        cin >> query;
        while(query!="END"){
            if(query == "M"){
                int x;
                int y;
                cin >> x;
                cin >> y;
                cout << FenwickTree.query(y) - FenwickTree.query(x-1) << "\n";
            }
            else{
                int x;
                int r;
                cin >> x;
                cin >> r;
                FenwickTree.update(x, r-(FenwickTree.query(x)-FenwickTree.query(x-1)));
            }
            cin >> query;
        }
        case_number++;
        cin >> N;
        if(N != 0){
            cout << "\n";
        }
    }
    return 0;
}