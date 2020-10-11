/**
 * @author      : Luis Miguel Baez <es.luismiguelbaez@gmail.com>
 * @created     : `!v strftime("%B %d, %Y")`
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define finally(value) {cout << (value) << '\n'; return;}

class Task {
private:
    
    void solveOne(istream &in, ostream &out) {
        
    }

public:
    void solve(istream &in, ostream &out) {
        int t=1;
        in >> t;
        while(t--) solveOne(in, out);
    }
};

void set_usaco(string filename="") {
    if(int(filename.size())) {
        freopen((filename+".in").c_str(), "r", stdin);
        freopen((filename+".out").c_str(), "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set_usaco("");
    
    Task solver;
    istream &in(cin);
    ostream &out(cout);
    solver.solve(in, out);
    return 0;
}

// COSAS A TENER EN CUENTA
//   * int overflow, limites de tiempo y memoria
//   * Caso especial (n=1?)
//   * Haz algo en lugar de nada y mantente organizado
//   * No se quede en un solo enfoque

// LIMITES DE TIEMPO Y MEMORIA
//   * 1 Segundo es Aproximadamente 10^8 Operaciones (c++)
//   * 10^6 Elementos de 32 Bits (4 bytes) es igual a 4 MB
//   * 62x10^6 Elementos de 32 Bits (4 bytes) es igual a 250 MB
//   * 10^6 Elementos de 64 Bits (8 bytes) es igual a 8 MB
//   * 31x10^6 Elementos de 64 Bits (8 bytes) es igual a 250 MB