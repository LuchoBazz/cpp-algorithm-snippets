vector<string> split(string str, string separator) {
    vector<string> tokens;
    for ( auto tok = strtok(&str[0], separator.data());
            tok != NULL;
            tok = strtok(NULL, separator.data())) {
        tokens.push_back(tok);
    }
    return tokens;
}
// Usage:
//   vector<string> tokens = split(str, "sep");