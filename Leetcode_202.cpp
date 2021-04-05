/*
* 202. 快乐数
*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。

提示：
	1 <= n <= 231 - 1
* 
* 解题思路： 
*   
*/

class Solution {
public:
    bool isHappy(int n) {
        int slowNum = n;
        int fastNum = n;
        do{
            slowNum = getSum(slowNum);
            fastNum = getSum(getSum(fastNum));
        }while(fastNum != 1 && slowNum != fastNum);
        return fastNum == 1;
    }

    int getSum(int n){
        int sum = 0;
        while(n > 0)
        {
            int d = n%10;
            sum += d*d;
            n /=10;
        }
        return sum;
    }
};