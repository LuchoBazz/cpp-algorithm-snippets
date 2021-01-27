const int ALPHA = ...; // alphabet size
const char L = ...; // first letter of the alphabet

struct TrieNode {
    int next[ALPHA];
    int fail, fail_out;
    // variables
    bool end : 1;
    int cnt;
    vector<int> idxs;
    
    TrieNode() {
        fill(next, next + ALPHA, 0);
        fail_out = fail = 0;
        // initialize variables
        end = false;
        cnt = 0;
    }
    int& operator[](int idx) {
        return next[idx];
    }
};

class AhoCorasick {
public:
    
    int nodes;
    int n;
    vector<TrieNode> trie;
    vector<string> words;

    AhoCorasick(const vector<string> &words) : nodes(0), words(words) {
        trie.emplace_back();
        n = (int) words.size();
        int idx = 0;
        for(const string &word: words)
            insert(word, idx++);
        build_ac();
    }

private:
    // insert into trie
    void insert(const string &word, int idx) {
        int state = 0;
        for(const char &ch :word) {
            int c = ch - L;
            if(!trie[state][c]) {
                trie.emplace_back();
                trie[state][c] = ++nodes;
            }
            state = trie[state][c];
        }
        // variables
        trie[state].end = true;
        trie[state].cnt++;
        trie[state].idxs.push_back(idx);
    }

    // create automaton
    void build_ac() {
        queue<int> q;
        // base cases
        for(int ch = 0; ch < ALPHA; ++ch) {
            if(trie[0][ch]) {
                trie[trie[0][ch]].fail = 0;
                trie[trie[0][ch]].fail_out = 0;
                q.push(trie[0][ch]);
            }
        }
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int ch = 0; ch < ALPHA; ++ch) {
                if(trie[node][ch]) {
                    int failure = trie[node].fail;
                    while(failure > 0 && !trie[failure][ch])
                        failure = trie[failure].fail;
                    
                    // create failure
                    failure = trie[failure][ch];
                    trie[ trie[node][ch] ].fail = failure;
                    // create failure out
                    if(trie[failure].end) {
                        trie[ trie[node][ch] ].fail_out = failure;
                    } else {
                        trie[ trie[node][ch] ].fail_out = trie[failure].fail_out;
                    }
                    // propagate information
                    trie[ trie[node][ch] ].cnt += trie[failure].cnt;

                    // add to queue
                    q.push(trie[node][ch]);
                }
            }
        }
    }
public:
    // search in automaton aho corasick
    vector<vector<int>> search(const string &text) {
        vector<vector<int>> answer(n);
        int state = 0;
        for(int i = 0; i < (int) text.size(); ++i) {
            int c = text[i] - L;
            while(state > 0 && !trie[state][c])
                state = trie[state].fail;
            state = trie[state][c];
            
            // traverse fail out
            int aux = state;
            while(aux) {
                if(trie[aux].end) {
                    // process something
                    for(const int &idx: trie[aux].idxs) {
                        answer[idx].push_back(i - (int) words[idx].size()+1);
                    }
                }
                aux = trie[aux].fail_out;
            }
        }
        return answer;
    }
};