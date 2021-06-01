/*
* 389. 找不同
*
给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。

提示：
0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母

* 
* 解题思路： 
*   1.使用异或
*   2.使用减法
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(int i=0;i<s.length();++i){
            res ^= t[i];
            res ^= s[i];
        }
        res ^= t[s.length()];
        return res;
    }
};

class Solution2 {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(int i=0;i<s.length();++i){
            res += t[i] - s[i];
        }
        res += t[s.length()];
        return res;

    }
};