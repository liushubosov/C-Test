/*
* 594. 最长和谐子序列
*
* 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
* 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
*
输入: [1,3,2,2,5,2,3,7]
输出: 5
原因: 最长的和谐数组是：[3,2,2,2,3].
说明: 输入的数组长度最大不超过20,000.
* 
* 解题思路： 
*   使用 map ，记录每个值的出现次数
*   遍历 map，查找 数值i 的次数和数值 i+1 的次数，是否比当前最大值更大
*   
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int,int> myMap;
        int nSize = nums.size();
        int nPreCount=0;
        for(int i=0;i < nSize;i++){
            if(myMap.count(nums[i]) == 0)
                myMap[nums[i]] = 1;
            else
                myMap[nums[i]]++;
        }
        
        for(auto iter=myMap.begin();iter != myMap.end();iter++){
             if(myMap.count(iter->first + 1) != 0){
                 nPreCount = max(nPreCount, iter->second + myMap[iter->first + 1]);
             }
            
        }
        return nPreCount;
    }
};
