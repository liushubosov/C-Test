//62. 不同路径
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

提示：
1 <= m, n <= 100
题目数据保证答案小于等于 2 * 109

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        //动态规划
        //状态定义：设定动态规划矩阵dp，dp[i][j]代表从网格左上角, 到达(i,j)坐标的所有路径总数量
        //转移方程：
        //  i=0, j=0 , dp[i][j] = 1
        //  i=0, j!=0, dp[i][j] = 1
        //  i!=0, j=0, dp[i][j] = 1
        //  i!=0, j!=0, dp[i][j] = dp[i-1][j] + dp[i][j-1]
        // 初始状态:
        //  dp[0][0] = 1
        // 返回值 dp[m-1][n-1] , 到达坐标(m,n)的所有路径数量
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for(int i=0;i < m;++i)
        {
            dp[i][0] = 1;
        }

        for(int i=0;i < n;++i)
        {
            dp[0][i] = 1;
        }

        for(int i=1;i < m;++i)
        {
            for(int j=1;j < n;++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};