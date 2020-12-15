/*
* 680. 验证回文字符串 Ⅱ
*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
示例 1:
    输入: "aba"
    输出: True

示例 2:
    输入: "abca"
    输出: True
    解释: 你可以删除c字符。
* 注意:  字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
* 
*
* 
* 解题思路： 
*   双指针遍历字符串
*       如果没找到不同字符，返回 true
*       如果找到不同字符，删除一个不同字符，再判断剩余的字符串是否构成回文
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int left=0, right=s.length()-1;
        while(left < right)
        {
            if(s[left] != s[right])
            {
                if(vaildStr(s.substr(0,left) + s.substr(left+1)) || vaildStr(s.substr(0,right) + s.substr(right+1)) )
                    return true;
                else
                    return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool vaildStr(string s)
    {
        int left=0, right=s.length()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};