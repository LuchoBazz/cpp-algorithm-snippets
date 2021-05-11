double max_value = 1e9 + 7;
double index = 0.0;
double jump = max_value;
for(int iter = 0; iter < 100; ++iter) {
    if(jump+index<max_value && !ok(jump+index)) {
        index += jump;
    }
    jump /= 2.0;
}
// index