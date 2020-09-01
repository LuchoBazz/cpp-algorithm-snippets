template<class T>
bool is_prime(T number) {
    if(number <= 0) return false;
    else if(number <= 3) return true;
    if(number%2==0 || number%3==0) return false;
    for(T i = 5; i*i <= number; i += 6) {
        if(number%i==0 || number%(i+2)==0) {
            return false;
        }
    }
    return true;
}
// Time Complexity: O(sqrt(N)), Space Complexity:  O(1)
// usage:
//   int number = 210;
//   bool ans = is_prime(number);