/*
* 703. 数据流中的第 K 大元素
*

设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 返回当前数据流中第 k 大的元素。

示例：
    输入：
    ["KthLargest", "add", "add", "add", "add", "add"]
    [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
    输出：
    [null, 4, 5, 5, 8, 8]

解释：
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

提示：
1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
最多调用 add 方法 104 次
题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素

* 
* 解题思路： 
*   第一种方式，使用优先队列（底层是用堆来实现的）。
*    priority_queue<Type, Container, Functional>，  
*    Type 为数据类型， Container 为保存数据的容器， Functional 为数据比较方式。
*    后两个参数不写， Container 默认为 vector, Functional 为 operator <, 也就是大顶堆，队头元素最大。
*   本题为小顶堆。
*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> myQueue;
    int K;

    KthLargest(int k, vector<int>& nums) {
        for(int n: nums)
        {
            myQueue.push(n);
            if(myQueue.size() > k)
                myQueue.pop();
        }      
        K = k;
    }
    
    int add(int val) {
        myQueue.push(val);
        if(myQueue.size() > K)
            myQueue.pop();
        return myQueue.top();
    }
};

/**
 * 第二种方式， 使用 multiset。
 *      multiset 为可重复 Key 且自动排序的 set。
 * 
 * */
class KthLargest2 {
public:
    multiset<int> mySet;
    int K;

    KthLargest(int k, vector<int>& nums) {
        for(int n: nums)
        {
            mySet.insert(n);
            if(mySet.size() > k)
                mySet.erase(mySet.begin());
        }      
        K = k;
    }
    
    int add(int val) {
        mySet.insert(val);
        if(mySet.size() > K)
            mySet.erase(mySet.begin());
        return *mySet.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */