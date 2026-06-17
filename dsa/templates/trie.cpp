// =============================================
// TRIE (PREFIX TREE) TEMPLATE
// Use when: autocomplete, prefix search, word dictionary, word search
// =============================================

struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string& word) {
        TrieNode* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string& prefix) {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* find(string& s) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) return nullptr;
            node = node->children[idx];
        }
        return node;
    }
};

// PROBLEMS USING THIS:
// - LC 208. Implement Trie (this template directly)
// - LC 211. Design Add and Search Words (Trie + DFS for '.' wildcard)
// - LC 212. Word Search II (Trie + grid backtracking)
// - LC 1268. Search Suggestions System (Trie + DFS for autocomplete)
// - LC 336. Palindrome Pairs (Trie for reverse prefix matching)
