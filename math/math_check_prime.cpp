template<class T>
bool isPrime(T number) {
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
// usage:
//   bool ans = isPrime(number);