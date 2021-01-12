/*
* 剑指 Offer 40. 最小的k个数
*
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

限制：

    0 <= k <= arr.length <= 10000
    0 <= arr[i] <= 10000
* 
* 解题思路： 
*   1. 使用 sort
*   2. 使用大堆顶 priority_queue
*/

//1
class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        for(int i=0;i < k;++i){
            res.push_back(arr[i]);
        }
        return res;
    }
};

//2
class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0) return {};
        vector<int> res;
        priority_queue<int> myqueue;
        for(int i=0;i < k;++i){
            myqueue.push(arr[i]);
        }

        for(int i=k;i < arr.size();++i){
            if(myqueue.top() > arr[i]){
                myqueue.pop();
                myqueue.push(arr[i]);
            }
        }

        while(!myqueue.empty()){
            res.push_back(myqueue.top());
            myqueue.pop();
        }
        return res;
    }
};