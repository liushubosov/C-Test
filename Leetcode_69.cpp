/*
* 69. x 的平方根
*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2

说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

* 
* 解题思路： 
*   二分查找
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int l = 0, r = x, res = -1;
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if((long long )mid*mid <= x)  //int可能会溢出，强转为long long
            {
                l = mid + 1;
                res = mid;
            }
            else
                r = mid -1;
        }
        return res;
    }
};