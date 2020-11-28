/*
* 504. 七进制数
*
给定一个整数，将其转化为7进制，并以字符串形式输出。

(注：分数越高的选手，排名越靠前。)
示例 1:

输入: 100
输出: "202"

输入: -7
输出: "-10"

* 
* 解题思路： 
*   可能是负数，先把负数转正，最后在字符串开头加个 -
*   类似十进制，mod = n%7,mod是当前位的值，n /= 7,从低位一直循环到最高位
*   把求得的字符串反转即可
*/

string convertToBase7(int num)
{
    bool bFlag = false;
    if (num == 0)
        return "0";
    else if (num < 0)
    {
        num *= -1;
        bFlag = true;
    }
    string res;
    while (num)
    {
        res.push_back((num % 7) + '0');
        num /= 7;
    }
    if (bFlag)
        res.push_back('-');
    reverse(res.begin(), res.end());
    return res;
}