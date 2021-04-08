/*
* 204. 计数质数
*
统计所有小于非负整数 n 的质数的数量。

提示：
	0 <= n <= 5 * 106
* 
* 解题思路： 
*   筛选法
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n,true);
        int count = 0;
        for(int i=2;i < n;++i)
        {
            if(primes[i])
            {
                ++count;
                for(int j=i+i;j < n;j+=i)
                    primes[j] = false;
            }
        }
        return count;
    }
};