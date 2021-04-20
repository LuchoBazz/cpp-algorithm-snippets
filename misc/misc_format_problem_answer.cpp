string operator "" _format(const char* lit, size_t n) {
    string s(lit);
    if(s=="I") return "IMPOSIBLE"; if(s=="i") return "imposible";
    if(s=="Y") return "YES"; if(s=="y") return "Yes";
    if(s=="N") return "NO"; if(s=="n") return "No";
    return s;
};