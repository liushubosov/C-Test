/*
* 88. 合并两个有序数组
*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]

示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]

提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
* 
* 解题思路： 
*   从后往前遍历两个数组，同时比较数组值，从后往前给数组1赋值
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0 ){
            nums1 = nums2;
            return;
        }
        if(n == 0)
            return;       
        int max = m + n - 1;
        int pos1 = m-1;
        int pos2 = n-1;
        while(pos1 >=0 && pos2 >=0)
        {
            int x = nums1[pos1];
            int y = nums2[pos2];
            if(x == y)
            {
                nums1[max] = x;
                nums1[--max] = y;
                --pos1;
                --pos2;
            }
            else if(x > y)
            {
                nums1[max] = x;
                --pos1;
            }else
            {
                nums1[max] = y;
                --pos2;
            }
            --max;
        }
        for(;pos2 >=0;--pos2)
        {
            nums1[max--] = nums2[pos2];
        }
    }
};