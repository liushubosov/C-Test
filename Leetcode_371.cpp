/*
* 371. 两整数之和
*
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:
输入: a = 1, b = 2
输出: 3

示例 2:
输入: a = -2, b = 3
输出: 1

* 
* 解题思路： 
*   使用位运算异或保存无进位的值 a，使用 位运算与 得出进位的值 b
*   b 左移一位。
*   循环，直到进位值为0
*   
*/

class Solution {
public:
    int getSum(unsigned int a, unsigned int b) {
        while(b != 0){
            unsigned int temp = a^b; 
            b = (a&b) << 1;
            a = temp;
        }
        return a;
    }
};