const int MOD = 1e9+7;
template<typename T>
class Matrix {
public:
    vector<vector<T>> M;
    int row, col;
    
    Matrix(const vector<vector<T>> &m) : M(m) {
        int n = int(m.size());
        row = n;
        if(n == 0) col = 0;
        else col = int(m[0].size());
    }
    
    Matrix(int r, int c, bool iden = false) : row(r), col(c) {
        assert(0 <= row && 0 <= col);
        M.resize(row, vector<T>(col, T(0)));
        if(iden) for(int i = 0; i < r; i++) M[i][i] = T(1);
    }
    
    Matrix<T> operator * (const Matrix<T> &other) const {
        Matrix<T> product(row, other.col);
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < other.col; j++) {
                T &ref = product.M[i][j];
                for (int k = 0; k < col; k++) {
                    // ref = (ref +  M[i][k] * other.M[k][j]) % MOD;
                    ref += M[i][k] * other.M[k][j];
                }
            }
        }
        return product;
    }
};
// Usage:
// Matrix<int> A(10, 20); or
// vector<vector<int>> vector1 {{1, 2}, {2, 3}};
// Matrix A(vector1);

template<typename T>
string to_string(const Matrix<T> &mat) {
    return to_string(mat.M);
}