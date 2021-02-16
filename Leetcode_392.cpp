/*
* 392. 判断子序列
*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
进阶：
如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

示例 1：
输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：
输入：s = "axc", t = "ahbgdc"
输出：false

提示：
0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。

* 
* 解题思路： 
*   1.遍历 s字符串， 使用 t.find(char, pos) 进行查找，如果找到该字符，那么 find的返回值 pos就作为下次查找的起始位置
*       如果没找到，返回 false
*   2.遍历 t 字符串，找到 s 中的字符，j++，最后判断 j 长度是否等于 s 的长度
*   3. Solution2 的优化版, 使用双指针。s 和 t 一起遍历，s的下标为 i， t的下标为 j；
*       如果s[i] == t[j] , i++; 否则 s 的下标不变
*       而 t 的下标一直在递增， j++
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.empty() && t.empty()) return false;
        size_t nBegin = 0;
        for(int i=0;i < s.length();i++){
            size_t n = t.find(s[i],nBegin);
            if(n == string::npos)
                return false;
            else
                nBegin = n + 1;
        }
        return true;
    }
};


class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        int j=0, sLen = s.length();
        for(const auto &c : t)
        {
            if(j < sLen && s[j] == c)
                ++j;
        }
        return sLen == j;
    }
};


class Solution3 {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0, sLen = s.length(), tLen = t.length();
        while(i < sLen && j < tLen)
        {
            if(s[i] == t[j++])
                ++i;
        }
        return i == sLen;
    }
};