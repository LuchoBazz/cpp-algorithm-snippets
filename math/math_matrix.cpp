const int MOD = 1e9+7;
template<typename T>
class Matrix {
public:
    vector<vector<T>> M;
    int row, col;
    
    Matrix(const vector<vector<T>> &m) : M(m) {
        int n = (int) m.size();
        row = n;
        if(n == 0)
            col = 0;
        else
            col = (int) m[0].size();
    }
    
    Matrix(int r, int c, bool iden = false) : row(r), col(c) {
        assert(0 <= row && 0 <= col);
        M.resize(row, vector<T>(col, T(0)));
        if(iden) 
            for(int i = 0; i < r; i++) 
                M[i][i] = T(1);
    }
    
    typename vector<vector<T>>::iterator begin() { return M.begin(); }
    typename vector<vector<T>>::iterator end() { return M.end(); }
    int size() { return (int) M.size(); }
    vector<T>& operator [] (int i) { return M[i]; }
    
    Matrix<T> operator * (Matrix<T> &other) const {
        assert(col==other.row);
        Matrix<T> product(row, other.col);
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < other.col; j++) {
                T &ref = product[i][j];
                for (int k = 0; k < col; k++) {
                    // ref = (ref +  M[i][k] * other[k][j]) % MOD;
                    ref += (M[i][k] * other[k][j]);
                }
            }
        }
        return product;
    }
    
    Matrix<T> operator + (Matrix<T> &other) const {
        assert(row==other.row && col==other.col);
        Matrix<T> ans(row, col);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                // ans[i][j] = (M[i][j] + other[i][j]) % MOD;
                ans[i][j] = M[i][j] + other[i][j];
            }
        }
        return ans;
    }

    Matrix<T> operator - (Matrix<T> &other) const {
        assert(row==other.row && col==other.col);
        Matrix<T> ans(row, col);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                // ans[i][j] = (M[i][j] - other[i][j] + MOD) % MOD;
                ans[i][j] = (M[i][j] - other[i][j]);
            }
        }
        return ans;
    }
    
};

template<typename T>
string to_string(const Matrix<T> &mat) {
    return to_string(mat.M);
}

template<typename T>
using matrix = Matrix<T>;
// Usage:
// matrix<int> A(10, 20); or
// vector<vector<int>> vector1 {{1, 2}, {2, 3}};
// matrix A(vector1);