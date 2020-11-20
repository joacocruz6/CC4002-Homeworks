#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DFT {
    vector<vector<long long> > fenwick_tree;

    DFT(int nx, int ny){
        for(int x = 0; x < nx; x++){
            vector<long long> column(ny, 0);
            fenwick_tree.push_back(column);
        }
    }

    long long query(int x, int y){
        long long sum = 0;
        while(x!=0){
            int ty = y;
            while(ty!=0){
                sum += fenwick_tree[x][ty];
                ty -= (ty & (-ty));
            }
            x -= (x & (-x));
        }
        return sum;
    }

    void update(int x, int y, long long val){
        while(x < fenwick_tree.size()){
            long long ty = y;
            while(ty < fenwick_tree[x].size()){
                fenwick_tree[x][ty] += val;
                ty += (ty & (-ty ));
            }
            x += (x & (-x));
        }
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t){
        int N;
        cin >> N;
        DFT FenwickTree(N+1,N+1);
        string query;
        cin >> query;
        while(query != "END"){
            if(query == "SET"){
                long long x;
                long long y;
                long long num;
                cin >> x;
                cin >> y;
                cin >> num;
                x++;
                y++;
                FenwickTree.update(x,y, num - (FenwickTree.query(x,y) - FenwickTree.query(x-1,y) - FenwickTree.query(x,y-1) + FenwickTree.query(x-1, y-1)));
            }
            else{
                long long x1;
                long long y1;
                long long x2;
                long long y2;
                cin >> x1;
                cin >> y1;
                cin >> x2;
                cin >> y2;
                x1++;
                x2++;
                y1++;
                y2++;
                long long result = FenwickTree.query(x2,y2) - FenwickTree.query(x1-1,y2) - FenwickTree.query(x2,y1-1) + FenwickTree.query(x1-1,y1-1);
                cout << result << "\n";
            }
            cin >> query;
        }
        t--;
        if(t){
            cout << "\n";
        }
    }
    return 0;
}