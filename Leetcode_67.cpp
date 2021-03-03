/*
* 67. 二进制求和
*
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
 
提示：
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

* 
* 解题思路： 
*   从字符串右边开始遍历
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.length(), blen=b.length(), c=0;
        string res;
        while(alen>0 || blen>0){
            // int tmpa = alen==0?0:(a[--alen] - '0');
            // int tmpb = blen==0?0:(b[--blen] - '0');
            // int tmps = tmpa+tmpb+c;
            int tmps = (alen==0?0:(a[--alen] - '0')) + (blen==0?0:(b[--blen] - '0')) + c;
            c = tmps/2;
            res.insert(res.begin(), (tmps%2)+'0');
        }
        if(c != 0)
            res.insert(res.begin(), c+'0');
        return res;
    }
};