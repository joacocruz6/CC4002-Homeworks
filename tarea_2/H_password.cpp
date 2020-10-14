#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
bool is_valid_character(char character, vector<string> second_grid, int index){
    for(int i=0; i<second_grid.size(); i++){
        if(character == second_grid[i][index]){
            return true;
        }
    }
    return false;
}
vector<string> make_possible_passwords(vector<string> first_grid, vector<string> second_grid){
    set<string> passwords; 
    passwords.insert("");
    for(int j = 4; j>=0; j--){
        set<string> possible_passwords; 
        for(int i = 0; i<first_grid.size(); i++){
            if(is_valid_character(first_grid[i][j], second_grid, j)){
                string character(1, first_grid[i][j]);
                for(auto password: passwords){
                    string s = character + password;
                    possible_passwords.insert(s);
                }
            }
        }
        passwords = possible_passwords;
    }
    vector<string> results(passwords.begin(), passwords.end());
    return results;
}



int main(){
    int T;
    cin >> T;
    while(T){
        int k;
        cin>>k;
        vector<string> first_grid;
        for(int i=0; i<6; i++){
            string s;
            cin>> s;
            first_grid.push_back(s);
        }
        vector<string> second_grid;
        for(int i=0; i<6; i++){
            string s;
            cin>> s;
            second_grid.push_back(s);
        }
        vector <string> passwords = make_possible_passwords(first_grid, second_grid);
        sort(passwords.begin(), passwords.end());
        
        if(k > passwords.size()){
            cout << "NO" << endl;
        }
        else{
            cout << passwords[k-1] << endl;
        }
        T--;
    }
    return 0;
}