#include <iostream>
#include <vector>

using namespace std;

void make_lotto_numbers(vector<int> S_set, int current_number_index, vector<int> answer){
    if(answer.size() == 6){
        cout << answer[0] << " ";
        cout << answer[1] << " ";
        cout << answer[2] << " ";
        cout << answer[3] << " ";
        cout << answer[4] << " ";
        cout << answer[5] << endl;
        return;
    }
    if(current_number_index >= S_set.size()){
        return;
    }
    answer.push_back(S_set[current_number_index]);
    make_lotto_numbers(S_set, current_number_index+1, answer);
    answer.pop_back();
    make_lotto_numbers(S_set, current_number_index+1, answer);

}

int main(){
    int k;
    cin >> k;
    while(k){
        vector<int> S_set;
        for(int i = 0; i<k; i++){
            int lotto_number;
            cin >> lotto_number;
            S_set.push_back(lotto_number);
        }
        vector<int> answer;
        make_lotto_numbers(S_set,0, answer);
        cin >> k;
        if(k){
            cout<<"\n";
        }
    }
    return 0;
}