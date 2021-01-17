/*
* 717. 1比特与2比特字符
*
有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。
现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。

示例 1:
    输入: 
    bits = [1, 0, 0]
    输出: True
    解释: 
    唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。

注意:
    1 <= len(bits) <= 1000.
    bits[i] 总是0 或 1.
* 
* 解题思路： 
*   方法1. 线性扫描，碰到 1 直接跳两位,碰到0 跳一位，最后看 i 能否走到 n-1
*   方法2. 计算两个 0 之间有几个 1， 如果是偶数，说明末尾的 0 不会被前边的 1 结合，返回 true
*/

//方法1
class Solution1 {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for(;i < bits.size()-1;++i)
        {
            i += bits[i];
        }
        return i == bits.size()-1;
    }
};

//方法2
class Solution2 {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = bits.size()-2;
        while(i >=0 && bits[i] > 0)  --i;
        return (bits.size() - i)%2 == 0;
    }
};