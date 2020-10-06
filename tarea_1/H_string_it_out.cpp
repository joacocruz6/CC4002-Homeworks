#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check_subsequence(string sub_sequence, string sequence, int elevated_number){
    int sub_sequence_length = sub_sequence.length();
    int sub_sequence_index = 0;
    int repetition = 0;
    for(int sequence_index = 0; sequence_index < sequence.length(); sequence_index++){
        if(sub_sequence_index == sub_sequence_length){
            return true;
        }
        if(sub_sequence[sub_sequence_index] == sequence[sequence_index]){
            repetition++;
            if(repetition == elevated_number){
                repetition = 0;
                sub_sequence_index++;
            }
        }
    }
    return false;
}

int get_max_elevated_number(string sub_sequence, string sequence){
    if(!check_subsequence(sub_sequence, sequence, 1)){
        return 0;
    }
    int initial = 1;
    int end = sequence.length() / sub_sequence.length();
    while(initial < end){
        int mid = initial + (end - initial) / 2;
        if(!check_subsequence(sub_sequence, sequence, mid)){
            end = mid;
        }
        else{
            initial = mid + 1;
        }
    }
    return initial;
}

int main(){
    int t;
    cin >> t;
    vector<int> answers;
    while(t!=0){
        string sub_sequence;
        string sequence;
        cin >> sub_sequence;
        cin >> sequence;
        int max_elevated_number = get_max_elevated_number(sub_sequence, sequence);
        answers.push_back(max_elevated_number);
        t--;
    }
    for(int i=0; i<answers.size(); i++){
        cout << answers[i] << endl;
    }
    return 0;
}