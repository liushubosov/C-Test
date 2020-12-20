/*
* 697. 数组的度
*

给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

* 
示例 1：

输入: [1, 2, 2, 3, 1]
输出: 2
解释: 
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.

*提示：
    nums.length 在1到50,000区间范围内。
    nums[i] 是一个在0到49,999范围内的整数。
* 
* 解题思路： 
*   使用结构体记录元素的个数，开始出现位置，最后出现位置。
*   第一次循环，取得所有元素的信息，使用 map 保存
*   第二次循环， 循环 map ， 找到最高频的元素，求得最小子数组
*/

class Solution {
public:
    struct Node{
        int count;
        int beginPos;
        int endPos;
    };
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, Node> myMap;
        for(int i=0;i < nums.size();i++)
        {
            if(myMap.count(nums[i]) == 0)
            {   
                Node node;
                node.count = 1;
                node.beginPos = i;
                node.endPos = i;
                myMap[nums[i]] = node;
            }
            else
            {
                myMap[nums[i]].count++;
                myMap[nums[i]].endPos = i;
            }

        }
        int res = INT_MAX, maxCnt = 0;
        for(auto& iter : myMap)
        {
            if(iter.second.count == maxCnt)
            {
                res = min(res, iter.second.endPos - iter.second.beginPos + 1);
            }
            else if(iter.second.count> maxCnt)
            {
                maxCnt = iter.second.count;
                res = iter.second.endPos - iter.second.beginPos + 1;
            }
        }
        return res;
    }
};