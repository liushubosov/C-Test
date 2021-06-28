/*
* 409. 最长回文串
*
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:
输入:
"abccccdd"
输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

* 
* 解题思路： 
*   不是找最长回文子串，而是找到字符串中的字符，它们可以拼出来的，最长回文串。
*   因此，这道题实际上是求出所有的偶数字符。
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char,int> myMap;
        //得出所有字符的个数
        for(auto &c : s){
            ++myMap[c];
        } 
        //字符个数相加，遇到奇数个字符，就减 1    
        for(auto iter=myMap.begin();iter != myMap.end();++iter){
            res += iter->second;
            if((iter->second%2) == 1)           
                --res;
        }
        //回文的中央可以放一个单独的字符，因此如果回文没有达到字符串长度，加1
        if(res != s.length())
            ++res;
        return res;
    }
};