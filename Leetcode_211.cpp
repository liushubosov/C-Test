/*
* 211. 添加与搜索单词 - 数据结构设计
*
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。
word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。

示例：

输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]

解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

* 
* 解题思路： 
*   构造前缀树
*/

class WordDictionary {
public:
    bool is_string;
    WordDictionary *next[26];
    /** Initialize your data structure here. */
    WordDictionary() {
        is_string = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Adds a word into the data structure. */
    void addWord(const string &word) {
        WordDictionary *p = this;
        for(const auto &w : word){
            if(p->next[w-'a'] == nullptr){
                p->next[w -'a'] = new WordDictionary();
            }
            p = p->next[w - 'a'];
        }
        p->is_string = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string &word) {
        WordDictionary *p = this;
        for(int i=0;i < word.size();++i){
            if(word[i] == '.'){
                string nextWord = word.substr(i+1);
                for(const auto &childP : p->next){
                    if(childP != nullptr){
                        if(childP->search(nextWord))
                            return true;
                    }
                }
                return false;
            }else{
                if(p->next[word[i]-'a'] == nullptr){
                    return false;
                }
                p = p->next[word[i] - 'a'];
            }
        }
        return p->is_string;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */