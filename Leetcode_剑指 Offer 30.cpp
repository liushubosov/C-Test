/*
* 剑指 Offer 30. 包含min函数的栈
*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例 1：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.

限制：
    各函数的调用总次数不超过 20000 次

注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/

* 
* 解题思路： 
*   三个方法的时间复杂度都是O(1)，这用链表比较好，链表修改快，节点存储的信息也多
*/

struct MyNode{
    MyNode * prev;
    int m;
    int val;
    MyNode(): prev(nullptr){}
    MyNode(MyNode *p, int curmin, int v): prev(p), m(curmin), val(v){}
};
class MinStack {
private:
    MyNode *tailNode;
public:
    /** initialize your data structure here. */
    MinStack() {
        tailNode = new MyNode();
    }
    ~MinStack() {
        while(tailNode){
            MyNode *tmp = tailNode;
            tailNode = tailNode->prev;
            delete tmp;
        }
    }
    
    void push(int x) {
        MyNode *p = new MyNode(tailNode, tailNode->prev?::min(tailNode->m, x):x, x);
        tailNode = p;
    }
    
    void pop() {
        MyNode *cur = tailNode;
        tailNode = tailNode->prev;
        delete cur;
    }
    
    int top() {
        return tailNode->val;
    }
    
    int min() {
        return tailNode->m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */