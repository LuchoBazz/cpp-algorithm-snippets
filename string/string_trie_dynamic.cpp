const int ALPHABET = 26;

class TrieNode {
public:
    array<TrieNode*, ALPHABET> children;
    bool isEnd;
    TrieNode() {
        children.fill(NULL);
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        if(n==0) return;
        TrieNode* tmp = root;
        int index = 0;
        for(int i = 0; i < n; ++i) {
            index = word[i] - 'a';
            if(tmp->children[index] == NULL) {
                tmp->children[index] = new TrieNode();
            }
            tmp = tmp->children[index];
        }
        tmp->isEnd = true;
    }
    
    bool search(string word) {
        int n = word.size();
        if(n == 0) return false;
        TrieNode* tmp = root;
        int index = 0;
        for(int i = 0; i < n; ++i) {
            index = word[i] - 'a';
            if(tmp->children[index] == NULL) {
                return false;
            }
            tmp = tmp->children[index];
        }
        return (tmp!=NULL)?tmp->isEnd:false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        if(n==0) return false;
        TrieNode* tmp = root;
        int index = 0;
        for(int i = 0; i < n; ++i) {
            index = prefix[i] - 'a';
            if(tmp->children[index] == NULL) {
                return false;
            }
            tmp = tmp->children[index];
        }
        return true;
    }
    
    vector<string> getWordsWithPrefix(string prefix) {
        vector<string> words;
        int n = prefix.size();
        if(n == 0) return words;
        int index = 0;
        TrieNode* tmp = root;
        for(int i = 0; i < n; ++i) {
            index = prefix[i] - 'a';
            if(tmp->children[index] == NULL) {
                return words;
            }
            tmp = tmp->children[index];
        }
        dfs(tmp, prefix, words);
        return words;
    }
    
    vector<string> getWords() {
        vector<string> words;
        dfs(root, "", words);
        return words;
    }
    
    void dfs(TrieNode* node, string characters, vector<string> &words) {
        if(isEmpty(node)) return;
        if(node->isEnd) {
            words.push_back(characters);
        }
        string newWord = "";
        int n = ALPHABET;
        for(int i = 0; i < n; ++i) {
            if(!isEmpty(node->children[i])) {
                newWord = characters + (char)(i+'a')+"";
                dfs(node->children[i], newWord, words);
            }
        }
    }
    
    bool isEmpty(TrieNode* node) {
        return node == NULL;
    }
};

// Time Complexity: O(n), Space Complexity: O(n*ALPHABET)