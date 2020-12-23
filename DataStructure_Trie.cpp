/**
 * 数据结构：前缀树
 * 
 * 什么是前缀树？
 * 前缀树是N叉树的一种特殊形式。
 * 通常来说，一个前缀树是用来存储字符串的。前缀树的每一个节点代表一个字符串（前缀）。
 * 每一个节点会有多个子节点，通往不同子节点的路径上有着不同的字符。
 * 子节点代表的字符串是由节点本身的原始字符串，以及通往该子节点路径上所有的字符组成的。
 * 
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Trie {
private:
    struct TrieNode {
        unordered_map<char, int> nextMap;
        bool bEnd = false;
    };
    vector<TrieNode> trie;

public:
    Trie() {
        trie.clear();
        //TrieNode() 和 new TrieNode() 差别在哪？
        //TrieNode() 是一个对象； new TrieNode() 是一个指针
        trie.push_back(TrieNode()); 
    }

    void insert(const string& word) {
        //方式一：递归
        insert(0, word, 0);

        //方式二：迭代
        int treeID = 0;
        for(const auto &w : word){
            if(trie[treeID].nextMap.count(w) == 0){
                trie[treeID].nextMap[w] = trie.size();
                trie.push_back(TrieNode());
            }
            treeID = trie[treeID].nextMap[w];
        }
        trie[treeID].bEnd = true;
    }

    bool search(const string& word) {
        bool bFlag = false;
        //方式一：递归
        bFlag = search(0, word, 0);

        //方式二：迭代
        int treeID = 0;
        for(const auto &w : word){
            if(trie[treeID].nextMap.count(w) == 0 || !trie[ trie[treeID].nextMap[w] ].bEnd){
                return false;
            }
            treeID = trie[treeID].nextMap[w];
        }
        bFlag = true;
        return bFlag;
    }

private:
    void insert(int treeID, const string& word, int nPos) {
        //如果递归到 字符串的最后一位，那么就可以停止了。
        if (nPos = word.size()) {
            trie[treeID].bEnd = true;
            return;
        }
        //如果字符串的当前位 不是当前树节点的子节点，那就创建该子节点。
        // 在 list 中存入该子节点
        // 在 nextMap 中存入该子节点在 list 的真实位置
        if (trie[treeID].nextMap.count(word[nPos]) == 0) {
            trie[treeID].nextMap[word[nPos]] = trie.size();
            trie.push_back(TrieNode());
        }
        //继续递归插入字符串的下一位。
        insert(trie[treeID].nextMap[word[nPos]], word, nPos + 1);
    }


    bool search(int treeID, const string& word, int nPos) {
        //如果递归到 字符串的最后一位，那么就可以停止,返回当前节点的结束标志，看 word 是不是一个完整的句子
        if (nPos == word.size())
            return trie[treeID].bEnd;
        //如果当前节点没有子节点了，说明 word 不匹配。
        if (trie[treeID].nextMap.count(word[nPos]) == 0)
            return false;
        //继续递归， 看字符串的下一位是否在树中存在
        return search(trie[treeID].nextMap[word[nPos]], word, nPos+1);
    }

    bool startWith(int treeID, const string& prefix, int nPos) {
        if (nPos == prefix.size())
            return true;
        if (trie[treeID].nextMap.count(prefix[nPos]) == 0)
            return false;
        return startWith(trie[treeID].nextMap[prefix[nPos]], prefix, nPos + 1);
    }
};