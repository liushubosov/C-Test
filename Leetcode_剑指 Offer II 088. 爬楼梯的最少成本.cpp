//剑指 Offer II 088. 爬楼梯的最少成本
/*数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。

每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。

请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。

2 <= cost.length <= 1000
0 <= cost[i] <= 999
 /*
//转移方程:dp[i] = min(dp[i-2]+ cost[i-2], dp[i-1]+cost[i-1])
//状态定义， dp[i]代表当前的阶梯i所需要花费的最小体力
//初始状态 dp[0] = 0, dp[1] = 0
//返回值： dp[i] , 第i阶梯的最小价值
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const size_t arraySize = cost.size();
        int dp[arraySize+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=2; i <= arraySize; ++i)
        {
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
        }
        return dp[arraySize];
    }
};