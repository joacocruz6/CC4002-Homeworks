#include <iostream>
#include <vector>

using namespace std;

vector<int> get_labels(vector<long long> accumulated_worms, vector<long long> juicy_worms){
    vector<int> labels;
    for(int i=0; i<juicy_worms.size(); i++){
        long long juicy_worm = juicy_worms[i];
        int initial = 1;
        int end = accumulated_worms.size();
        while(initial < end){
            int mid = initial + (end - initial)/2;
            long long middle_worm = accumulated_worms[mid-1];
            if(juicy_worm <= middle_worm){
                end = mid;
            }
            else{
                initial = mid + 1;
            }
        }
        labels.push_back(end);
    }
    return labels;
}

int main(){
    int n;
    vector<long long> accumulated_worms;
    int m;
    vector<long long> juicy_worms;
    cin >> n;
    int first_pile;
    cin >> first_pile;
    accumulated_worms.push_back(first_pile);
    for(int i = 1; i<n; i++){
        long long a_i;
        cin >> a_i;
        accumulated_worms.push_back(accumulated_worms[i-1] + a_i);
    }
    cin >> m;
    for(int i = 0; i<m; i++){
        long long q_i;
        cin >> q_i;
        juicy_worms.push_back(q_i);
    }
    vector<int> answers = get_labels(accumulated_worms, juicy_worms);
    for(int i = 0; i< answers.size(); i++){
        cout << answers[i] << endl;
    }
    return 0;
}