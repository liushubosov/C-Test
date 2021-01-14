/*
* 976. 三角形的最大周长
*
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
如果不能形成任何面积不为零的三角形，返回 0。

示例：
输入：[2,1,2]
输出：5

输入：[1,2,1]
输出：0

限制：
    3 <= A.length <= 10000
    1 <= A[i] <= 10^6
* 
* 解题思路： 
*   两边之和大于第三边，因此先降序排序，再计算
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end(),greater<int>());
        for(int i=2;i < A.size();++i){
            if(A[i-2] < A[i-1] + A[i])
                return A[i-2] + A[i-1] + A[i];
        }
        return 0;
    }
};