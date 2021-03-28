/*
* 168. Excel表列名称
*
给定一个正整数，返回它在 Excel 表中相对应的列名称。
例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

* 
* 解题思路： 
*   类似十进制，有个特别点，没有 0， 从 1 开始。
*   因此每次循环都减一，，这样就跟普通的十进制没有区别。
*/
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n > 0)
        {
            n -= 1;
            res += n%26 + 'A';           
            n /= 26;            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};