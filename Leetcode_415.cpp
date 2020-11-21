/*
* 415. 字符串相加
*
* 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
*
* 1. num1 和num2 的长度都小于 5100
* 2. num1 和num2 都只包含数字 0-9
* 3. num1 和num2 都不包含任何前导零
* 4. 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
* 
* 解题思路： 
*   加法计算，有进位和当前位。
*   从数组右端开始，低位计算，当前位为空的话直接用零代替
*   最后反转字符串
*/

string addStrings(string num1, string num2)
{
    string res;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int add = 0;
    while (i >= 0 || j >= 0 || add != 0)
    {
        int a, b;
        a = i < 0 ? 0 : num1[i] - '0';
        b = j < 0 ? 0 : num2[j] - '0';
        int sum = a + b + add;
        res.push_back(sum % 10 + '0');
        add = sum / 10;
        i--;
        j--;
    }

    reverse(res.begin(), res.end());
    return res;
}