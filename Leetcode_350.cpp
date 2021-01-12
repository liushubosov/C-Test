/*
* 350. 两个数组的交集 II
*
给定两个数组，编写一个函数来计算它们的交集。


示例：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

说明:
输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
我们可以不考虑输出结果的顺序。

* 
* 解题思路： 
*   1.使用 map 记录第一个数组中元素出现的次数，第二个数组中出现相同元素次数减1
*   2.使用 set_intersection 计算交集
*/

//1
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mymap;
        for(const auto & n : nums1){
            if(mymap.find(n) != mymap.end())
                mymap[n]++;
            else
                mymap[n] = 1;
        }
        vector<int> res;
        for(const auto &n : nums2){
            if(mymap.find(n) != mymap.end() && mymap[n] > 0){
                res.push_back(n);
                mymap[n]--;
            }
        }
        return res;
    }
};

//2
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> set1(nums1.begin(), nums1.end());
        multiset<int> set2(nums2.begin(), nums2.end());
        vector<int> res;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(res, res.begin()));
        return res;
    }
};