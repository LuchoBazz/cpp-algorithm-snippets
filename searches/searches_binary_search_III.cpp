int n = oo;
int index = -1;
for(int jump = n+1; jump >= 1; jump /= 2) {
    while(jump+index<n && !ok(jump+index)) {
        index += jump;
    }
}
// index + 1