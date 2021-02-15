/*
* 5. 最长回文子串
*
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

提示：
    1 <= s.length <= 1000
    s 仅由数字和英文字母（大写和/或小写）组成

* 
* 解题思路： 
*   
*/

class Solution {
public:
    string longestPalindrome(string s) {
		int strLen = s.length();
		if (strLen < 2) return s;
        string res, temp;
        res = "";
        temp = "#";
        int l = 0, maxLen = 0;
        
        for(int j=0;j < strLen;j++)
        {
            temp += s[j] ;
            temp += '#';
        }
        
        for(int i=0;i < temp.length();i++)
        {
            int curL = i - 1;
            int curR = i + 1;
            while(curL >= 0 && curR < temp.length() && temp[curL] == temp[curR])
            {
                curL--;
                curR++;
            }
            
            int curLen = curR - curL - 1;
            if(curLen > maxLen)
            {
                maxLen = curLen;
                l = i - (maxLen-1)/2;
            }            
        }
        res = temp.substr(l, maxLen);   
        temp = res;
        res = "";
        
        for(int k=0;k < temp.length();k++)
        {
            if(temp[k] != '#')
                res += temp[k];
        }
        
		return res;
	}

};