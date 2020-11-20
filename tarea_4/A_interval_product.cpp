#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// Estructura
template<class T>
struct SegmentTree{
    vector<T>ST;
    int n;
    T (*merge)(int i, int l, int r, T a, T b);
    void build(int i, int l, int r, vector<T>&a){
        if (l==r){
            ST[i]=a[l];return;
        }

        build(i << 1, l, (l + r) >> 1, a);
        build(i << 1 | 1, (l + r) / 2 + 1, r, a);
        ST[i] = merge(i, l, r, ST[i << 1], ST[i << 1 | 1]);
    }
    SegmentTree(vector<T>&a, T (*merge)(int i, int l, int r, T a, T b)) : merge(merge){
        n=a.size();
        ST.resize(4 * n + 5);
        build(1, 0, n - 1, a);
    }
    void setMerge(T (*_merge)(int i, int l, int r, T a, T b)){
        merge = _merge;
    }
    SegmentTree(){

    }
    void buildSegmentTree(vector<T> &a){
        n = a.size();
        ST.resize(4 * n + 5);
        build(1, 0, n - 1, a);
    }
    void update(int i, int l, int r, int pos, T val){
        if (r < pos or l > pos)
            return;
        if (l == r){
            ST[i] = val;
            return;
        }
        update(i << 1, l, (l + r) >> 1, pos, val);
        update(i << 1 | 1, (l + r) / 2 + 1, r, pos, val);
        ST[i]=merge(i, l, r, ST[i << 1], ST[i << 1 | 1]);
    }
    T query(int i, int l, int r, int a, int b){
        if (l >= a and r <= b)
            return ST[i];
        int mid = (l + r) >> 1;
        if (b <= mid)
            return query(i << 1, l, (l + r) >> 1, a, b);
        if (a > mid)
            return query(i << 1 | 1, (l + r) / 2 + 1, r, a, b);
        return merge(i, l, r, query(2*i, l, (l+r)/2, a, b), query(2*i+1, (l+r)/2+1, r, a, b));
    }

    T query(int a, int b){
        return query(1, 0, n - 1, a, b);
    }

    void update(int pos, T val){
        update(1, 0, n - 1, pos, val);
    }
};


// Esta es la función que mezcla 2 nodos
// En este caso el segment tree tendrá en sus nodos los pares
// (x, y) donde x es el valor en la posición y
// Esto lo hacemos para hacer un segment tree
// de mínimos que además de entregar el mínimo entrega la posición
// donde éste se encuentra.


// Recibe el i, l, r porque a veces es necesario
// tener esa información al mezclar nodos
int merge1(int i, int l, int r, int A, int B){
    if(A > 0 && B > 0){
        return 1;
    }
    else if(A < 0 && B > 0){
        return -1;
    }
    else if(A < 0 && B < 0){
        return 1;
    }
    else if(A > 0 && B < 0){
        return -1;
    }
    return 0;   // Es simplemente el mínimo lexicográfico
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    while(cin >> n){
        int k;
        cin >> k;
        // Se crea el arreglo inicial
        vector<int>a(n,0);
        for (int i = 0; i < n; i ++){
            cin >> a[i];
        }

        // Es un segment tree de pares de enteros
        // donde el arreglo inicial de pares de enteros
        // es a y la función que mezcla dos nodos
        // es merge1
        
        SegmentTree<int > prodST(a, merge1);
        while(k--){
            string query;
            cin >> query;
            if(query == "C"){
                int I;
                int V;
                cin >> I;
                cin >> V;
                prodST.update(I-1, V);

            }
            else{
                int I;
                int J;
                cin >> I;
                cin >> J;
                int value = prodST.query(I-1,J-1);
                if(value > 0){
                    cout << "+";
                }
                else if(value == 0){
                    cout << "0";
                }
                else if (value < 0){
                    cout << "-";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}