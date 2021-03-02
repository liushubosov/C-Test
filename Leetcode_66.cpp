/*
* 66. 加一
*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

示例 3：
输入：digits = [0]
输出：[1]
 

提示：
1 <= digits.length <= 100
0 <= digits[i] <= 9

* 
* 解题思路： 
*   最好的情况是，末尾不是9，即便加1，也可以立马结束。
*   最坏情况是所有位都是9，需要一直加1，最后再在首位插入一位存1。
*   中间情况是最后几位是9，那么循环完这几个9，也可以结束
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = 1;
        for(int i=digits.size()-1;i >= 0;--i)
        {
            digits[i] += n;
            n = digits[i] / 10;
            if(n == 0) break;
            digits[i] %= 10;          
        }
        if(n != 0)
            digits.insert(digits.begin(),1);
        return digits;
    }
};