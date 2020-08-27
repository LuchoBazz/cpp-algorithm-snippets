template<class T>
vector<T> divisors(T number) {
    vector<T> solutions;
    // 1 <= i <= sqrt(number)
    for (T i = 1; i <= sqrt(number); ++i) {
        // if i is divisor of number
        if (number % i == 0) {
            if (number/i == i) {
                // if i*i == number
                solutions.push_back(i);
            } else {
                // x=i, y=number/i
                // if x*y==number
                solutions.push_back(i);
                solutions.push_back(number/i);
            }
        }
    }
    return solutions;
}
// usage:
//   int number = 100;
//   vector<int> ans = divisors<int>(number);