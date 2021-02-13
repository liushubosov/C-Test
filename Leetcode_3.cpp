/*
* 3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

提示：
    0 <= s.length <= 5 * 104
    s 由英文字母、数字、符号和空格组成

* 
* 解题思路： 
*   
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lit[128]{};
        int res=0;

        for(int j=0, i=0; j< s.length();++j)
        {
            i = max(i, lit[s[j]]);
            res = max(res, j - i  + 1);
            lit[s[j]] = j+1;
        }
        return res;
    }
};

