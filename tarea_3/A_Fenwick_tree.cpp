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
	int n;
	cin >> n;
	vector<long long> array;
	FT FenwickTree(n+1);
	for(int i=0; i<n; i++){
		long long value;
		cin >> value;
		FenwickTree.update(i+1, value);
	}
	int number_of_operations;
	cin >> number_of_operations;
	while(number_of_operations){
		string type_of_query;
		cin >> type_of_query;
		if(type_of_query == "q"){
			int l;
			int r;
			cin >> l;
			cin >> r;
			cout << FenwickTree.query(r) - FenwickTree.query(l-1) << "\n";
		}
		else{
			int i;
			long long x;
			cin >> i;
			cin >> x;
			FenwickTree.update(i, x);
		}
		number_of_operations--;
	}
	return 0;
}