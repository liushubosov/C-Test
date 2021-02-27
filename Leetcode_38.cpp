/*
* 38. 外观数列
*
给定一个正整数 n ，输出外观数列的第 n 项。
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
你可以将其视作是由递归公式定义的数字字符串序列：
countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。

提示：
    1 <= n <= 30

* 
* 解题思路： 
*   对操作的模拟
*/
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        int level = 1;
        while(level < n)
        {
            ++level;
            char chr = result[0];
            int count = 1;
            string strTmp = "";
            string strD = "  ";
            for(int i=1;i < result.length();++i)
            {                
                if(chr == result[i])
                    ++count;
                else
                {
                    strD[0] = (char)(count + '0');
                    strD[1] = chr;
                    strTmp += strD;
                    chr = result[i];
                    count = 1;
                }
            }
            strD[0] = (char)(count + '0');
            strD[1] = chr;
            result = strTmp + strD;
        }
        return result;
    }
};