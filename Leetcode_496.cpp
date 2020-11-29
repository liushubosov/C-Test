/*
* 496. 下一个更大元素 I
*
* 给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
* nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
*
示例 1:
输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。

* 1.nums1和nums2中所有元素是唯一的。
* 2.nums1和nums2 的数组大小都不超过1000。

* 
* 解题思路： 
*/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int len2 = nums2.size();
        if (len2 == 0)
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                nums1[i] = -1;
            }
            return nums1;
        }
        unordered_map<int, int> myMap;
        vector<int> res;

        for (int i = 0; i < len2; i++)
        {
            myMap[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            int n = -1;
            for (int j = myMap[nums1[i]] + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums1[i])
                {
                    n = nums2[j];
                    break;
                }
            }
            res.push_back(n);
        }
        return res;
    }
};