/*
* 507. 完美数
*
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。
给定一个 整数 n， 如果是完美数，返回 true，否则返回 false

示例 1：
输入：28
输出：True
解释：28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, 和 14 是 28 的所有正因子。
*/
/* 
* 解题思路： 
*   先求出平方根，遍历从0到平方根，如果能被整除，说明是正因子
* 
*/

bool checkPerfectNumber(int num)
{
    if (num < 6)
        return false;
    int s = 1;
    for (int i = sqrt(num); i > 1; --i)
    {
        if (num % i == 0)
        {
            s += (num / i);
            //num=16, i=4
            if(i*i != num)
                s += i;
            if (s > num)
                return false;
        }
    }
    return s == num;
}