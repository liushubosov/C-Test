/*
* 125. 验证回文串
*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

* 
* 解题思路： 
*   
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        for(int i=0;i < s.length();++i)
        {
            if(s[i] >= 65 && s[i] <= 90 )
                result.push_back(s[i] += 32);
            else if((s[i] >=48 && s[i] <= 57) || (s[i] >=97 && s[i] <= 122))
                result.push_back(s[i]);
        }
        int i=0;
        int j = result.size() - 1;
        while(i < j)
        {
            if(result[i] != result[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};