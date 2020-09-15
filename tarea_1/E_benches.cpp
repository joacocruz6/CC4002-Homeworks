#include <iostream>
#include <vector>

using namespace std;

int amount_people_left(vector<int> benches, int people_number, int entering_people){
    int necesary_people = 0;
    for(int i=0; i<benches.size(); i++){
        if(benches[i] < people_number){
            necesary_people += people_number - benches[i];
        }
    }
    return entering_people - necesary_people;
}
int get_max_k(int max_bench_people, int people_entering_park){
    return max_bench_people+people_entering_park;
}
int get_min_k(vector<int> benches, int max_k, int entering_people, int maximum_bench){
    int initial = 0;
    int end = max_k;
    while(initial < end){
        int mid = initial + (end - initial)/2;
        int people_left = amount_people_left(benches, mid, entering_people);
        if(people_left > 0){
            initial = mid + 1;
        }
        if(people_left == 0){
            return mid >= maximum_bench ? mid: maximum_bench;
        }
        if(people_left < 0){
            end = mid;
        }
    }
    return initial >= maximum_bench ? initial: maximum_bench;
}
int main(){
    int n;
    int m;
    vector<int> benches;
    cin >> n;
    cin >> m;
    int maximum_bench = -1;
    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        if(input > maximum_bench){
            maximum_bench = input;
        }
        benches.push_back(input);
    }
    int max_k = get_max_k(maximum_bench, m);
    int min_k = get_min_k(benches, max_k, m, maximum_bench);
    cout << min_k << " " << max_k;
    return 0;
}