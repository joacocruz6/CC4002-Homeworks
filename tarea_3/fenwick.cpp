#include <vector>
#include <iostream>
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