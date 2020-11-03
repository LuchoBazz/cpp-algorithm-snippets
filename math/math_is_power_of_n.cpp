bool is_power_of_n(int number, int N) { 
    if(number == 0 || (number!=1 && N == 0)) return false; 
    else if(N == 1) return true;
    
    while(number != 1) {  
        if(number % N != 0)  {
            return false; 
        }
        number = number / N;  
    } 
    return true; 
} 