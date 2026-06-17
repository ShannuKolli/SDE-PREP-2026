# =============================================
# TRIE (PREFIX TREE) TEMPLATE
# Use when: autocomplete, prefix search, word dictionary, word search
# =============================================


class TrieNode:
    def __init__(self):
        self.children = {}   # dict is cleaner than [None]*26 in Python
        self.is_end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self._find(word)
        return node is not None and node.is_end

    def starts_with(self, prefix: str) -> bool:
        return self._find(prefix) is not None

    def _find(self, s: str):
        node = self.root
        for ch in s:
            if ch not in node.children:
                return None
            node = node.children[ch]
        return node


# PROBLEMS USING THIS:
# - LC 208. Implement Trie (this template directly)
# - LC 211. Design Add and Search Words (Trie + DFS for '.' wildcard)
# - LC 212. Word Search II (Trie + grid backtracking)
# - LC 1268. Search Suggestions System (Trie + DFS for autocomplete)
# - LC 336. Palindrome Pairs (Trie for reverse prefix matching)
