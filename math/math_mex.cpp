// Reference: https://cp-algorithms.com/sequences/mex.html
template <typename T> class Mex {
private:
    map<T, int> frequency;
    set<T> missing_numbers;
    vector<T> A;
    
public:
    Mex(vector<T> const &A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (T x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() { return *missing_numbers.begin(); }

    void update(int idx, T new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};