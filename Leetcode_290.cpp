/*
* 290. 单词规律
*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false

说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。   

* 解题思路：
*   1. 使用map
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(str.empty() || pattern.empty())
            return false;
        stringstream ss(str);
        string s;
        unordered_map<char,string> myMap1;
        unordered_map<string,char> myMap2;
        for(char chr : pattern){
            if(!(ss>>s)
                || (myMap1.count(chr) == 1 && myMap1[chr] != s)
                || (myMap2.count(s) == 1 && myMap2[s] != chr))
                return false;
            myMap1[chr] = s;
            myMap2[s] = chr;
        }
        return (ss>>s) ?false:true;
    }
};

