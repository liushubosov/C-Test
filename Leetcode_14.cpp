/*
* 14. 最长公共前缀
*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

提示：
0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成

* 
* 解题思路： 
*   
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size() == 0)
            return result;
        else if(strs.size() == 1)
            return strs[0];
        
        bool bFlag = false;
        string strBase = strs[0];
        for(int i=0;i < strBase.length();i++)
        {
            char cHead = strBase[i];
            for(int j=1;j < strs.size();j++)
            {
                if(strs[j][i] == cHead)
                    bFlag = true;
                else
                {
                    bFlag = false;
                    break;
                }
            }
            if(!bFlag)
                break;
            else
                result += cHead;
        }
        return result;
    }
};