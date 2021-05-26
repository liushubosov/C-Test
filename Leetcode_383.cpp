/*
* 383. 赎金信
*
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

提示：
你可以假设两个字符串均只含有小写字母。

* 
* 解题思路： 
*   1. 使用map
*   2. 使用字符数组
*/

class Solution1 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> myMap;
        for(int i=0;i < magazine.length();++i){
            if(myMap.count(magazine[i]) == 0)
                myMap[magazine[i]] = 1;
            else
                ++myMap[magazine[i]];
        }

        for(int j=0;j < ransomNote.length();++j){
            if(myMap.count(ransomNote[j]) == 0 || myMap[ransomNote[j]] < 1)
                return false;
            else{
                --myMap[ransomNote[j]];
            }
        }
        return true;
    }
};


class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for(const auto &c : magazine){
            ++cnt[c-'a'];
        }
        for(const auto &c : ransomNote){
            --cnt[c-'a'];
        }
        for(const auto &num: cnt){
            if(num < 0)
                return false;
        }
        return true;
    }
};