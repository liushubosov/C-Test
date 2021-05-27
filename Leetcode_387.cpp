/*
* 387. 字符串中的第一个唯一字符
*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

示例：
s = "leetcode"
返回 0

s = "loveleetcode"
返回 2

提示：你可以假定该字符串只包含小写字母。

* 
* 解题思路： 
*   
*/

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        int lt[26] = {0};
        for(int i=0;i<s.length();++i){
            int nPos = s[i]-'a';
            if(lt[nPos] == 0)
                lt[nPos] = i+1;
            else if(lt[nPos] > 0)
                lt[nPos] = -1;
        }
        for(int j=0;j < s.length();++j){
            if(lt[s[j]-'a'] > 0)
                return lt[s[j]-'a']-1;
        }
        return -1;
    }
};