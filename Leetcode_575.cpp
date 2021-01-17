/*
* 575. 分糖果
*
* 给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
* 示例 1:
*
* 输入: candies = [1,1,2,2,3,3]
* 输出: 3
* 解析: 一共有三种种类的糖果，每一种都有两个。
*     最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
* 
* 解题思路： 
*   用 set 计算糖果种类
*   妹妹最多可以分到 n/2 个糖， 因为是两个人平均分配，如果糖种类超过 n/2, 妹妹也分不到，应该立即 return n/2;
*/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        //unordered_set<int> mySet(candyType.begin(),candyType.end());
        unordered_set<int>  mySet;
        size_t candyLen = candyType.size();
        for(int i=0;i < candyLen && mySet.size() < candyLen/2;++i){
            mySet.insert(candyType[i]);
        }
        return mySet.size();
    }
};