/*
* 746. 使用最小花费爬楼梯
*
数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。

示例 1：
输入：cost = [10, 15, 20]
输出：15
解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。

示例 2：
输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出：6
解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。

注意：
    cost 的长度范围是 [2, 1000]。
    cost[i] 将会是一个整型数据，范围为 [0, 999] 。

* 
* 解题思路： 
*   动态规划。每次只能走一步或者两步，因此
*   每一步 i 的花费 cost，等于前一步 cost[i-1] 加上 dp[i-1]或者前前一步 cost[i-2] + dp[i-2] 
*/

//构造 dp 数组，保存每一步的最小花费。
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = dp[1] = 0;
        for(int i=2;i <= n;++i){
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};

//不使用 dp 数组，只需要保存前一步和前前一步的最小花费即可。
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pre=0, prepre=0;
        for(int i=2;i <= cost.size();++i){
            int cur = min(pre+cost[i-1], prepre+cost[i-2]);
            prepre=pre;
            pre = cur;
        }
        return pre;
    }
};