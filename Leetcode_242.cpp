/*
* 242. 有效的字母异位词
*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false

说明:
你可以假设字符串只包含小写字母。

*  
* 解题思路：
*   
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int lst[26]{0};
        for(int i=0;i<s.length();++i){
            ++lst[ s[i] - 'a' ];
        }

        for(int j=0;j<t.length();++j){
            --lst[ t[j] - 'a' ];

            if(lst[ t[j] - 'a' ] < 0)
                return false;
        }
        return true;
    }
};
