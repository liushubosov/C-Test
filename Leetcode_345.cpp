/*
* 345. 反转字符串中的元音字母
*
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1：
输入："hello"
输出："holle"

示例 2：
输入："leetcode"
输出："leotcede"
 

提示：
元音字母不包含字母 "y" 。

* 解题思路：
*   交换头尾的字母
*/

class Solution {
public:
    string reverseVowels(string s) {
        //a, e, i, o, u
        set<char> mySet {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
        int left=0, right=s.length()-1;
        int lFind=0, rFind=0;
        while(left < right){
            if(lFind == 0)
                lFind = mySet.count(s[left]);
            if(rFind == 0)
                rFind = mySet.count(s[right]);
            if(lFind ==1 && rFind == 1){
                if(s[left] != s[right])
                    swap(s[left],s[right]);
                lFind = 0;
                rFind = 0;
            }
            if(rFind == 0)
                --right;
            if(lFind ==0)
                ++left;
        }
        return s;
    }
};