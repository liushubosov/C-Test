/*
* 349. 两个数组的交集
*
给定两个数组，编写一个函数来计算它们的交集。


示例：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

说明:
输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

* 
* 解题思路： 
*   1.数组变为set，就去掉重复的了，再遍历set，就可以找到交集
*   2.使用 set_intersection 计算交集
*/

//1
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> list1(nums1.begin(),nums1.end());
        unordered_set<int> list2;
        for(const auto &n : nums2){
            if(list1.find(n) != list1.end()){
                list2.insert(n);
            }
        }
        return vector<int>(list2.begin(),list2.end());
    }
};

//2
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vtr;
        set<int> a(nums1.begin(),nums1.end());
        set<int> b(nums2.begin(),nums2.end());
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(vtr,vtr.begin()));
        return vtr;
    }
};