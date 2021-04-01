/*
* 189. 旋转数组
*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]

提示：

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

* 
* 解题思路： 
*   来自《编程珠玑》的思路，左旋右旋再整体旋转
*/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0 ) return;
        int len = nums.size();
        k %= len;
        k = k == 0?len:k;
        //三次旋转
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.begin()+(len-k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};