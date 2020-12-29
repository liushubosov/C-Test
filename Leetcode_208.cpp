/*
* 208. 实现 Trie (前缀树)
*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例：
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true

说明:
    你可以假设所有的输入都是由小写字母 a-z 构成的。
    保证所有输入均为非空字符串。

* 
* 解题思路： 
*   
*/

class Trie {
public:
    bool is_string;
    Trie *next[26];
    /** Initialize your data structure here. */
    Trie() {
        is_string = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(const string &word) {
        Trie *p = this;
        for(const auto &w : word){
            if(p->next[w-'a'] == nullptr){
                p->next[w-'a'] = new Trie();
            }
            p = p->next[w-'a'];
        }
        p->is_string = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        Trie *p = this;
        for(const auto &w : word){
            if(p->next[w-'a'] == nullptr )
                return false;
            p = p->next[w-'a'] ;
        }
        return p->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        Trie *p = this;
        for(const auto &w : prefix){
            if(p->next[w-'a'] == nullptr)
                return false;
            p = p->next[w-'a'] ;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */