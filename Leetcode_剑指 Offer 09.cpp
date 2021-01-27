/*
* 剑指 Offer 09. 用两个栈实现队列
*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

限制：
    1 <= values <= 10000
    最多会对 appendTail、deleteHead 进行 10000 次调用
* 
* 解题思路： 
*   一个栈只负责添加，另一个只负责删除
*/

class CQueue {
public:
    stack<int> headstack;
    stack<int> tailstack;
    CQueue() {

    }
    
    void appendTail(int value) {
        tailstack.push(value);
    }
    
    int deleteHead() {
        int res = -1;
        if(headstack.empty()){
            while(!tailstack.empty()){
                headstack.push(tailstack.top());
                tailstack.pop();
            }
        }
        if(!headstack.empty()){
            res = headstack.top();
            headstack.pop();
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */