/*
* 367. 有效的完全平方数
*
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。

提示：
1 <= num <= 2^31 - 1

* 
* 解题思路： 
*   1. 使用二分查找
*   2. 
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 1) return false;
        int left=0, right=num;
        long q = 0;
        while(left < right){
            long mid = left + (right-left)/2; 
            q = mid*mid;
            if(q == num)
                return true;
            else if(q > num)
                right = mid -1;   
            else
                left = mid + 1;
        }
        return left*left == num;
    }
};

class Solution2 {
public:
    bool isPerfectSquare(int num) {
        int q = 1;
        while(num > 0 ){
            num -= q;
            q += 2;
        }
        return num==0;
    }
};