class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        end = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int p = word[i] - 'a';
            if (!cur->children[p])
                cur->children[p] = new TrieNode();
            cur = cur->children[p];   // ✅ fixed
        }
        cur->end = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int p = word[i] - 'a';
            if (!cur->children[p]) return false;
            cur = cur->children[p];   // ✅ fixed
        }
        return cur->end;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            int p = prefix[i] - 'a';
            if (!cur->children[p]) return false;
            cur = cur->children[p];   // ✅ fixed
        }
        return true;
    }
};