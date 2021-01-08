/*
* 155. 最小栈
*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
    push(x) —— 将元素 x 推入栈中。
    pop() —— 删除栈顶的元素。
    top() —— 获取栈顶元素。
    getMin() —— 检索栈中的最小元素。


示例：
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

提示：
    pop、top 和 getMin 操作总是在 非空栈 上调用。

* 
* 解题思路： 
*   使用结构体保存当前值和当前最小值
*/

struct MyNode{
    MyNode * prev;
    int m;
    int val;
    MyNode(): prev(nullptr){
    }
    MyNode(MyNode *p, int curmin, int v): prev(p), m(curmin), val(v){}
};
class MinStack {
public:
    MyNode *root;
    /** initialize your data structure here. */
    MinStack() {
        root = new MyNode();
    }
    ~MinStack() {
        if(root){
            delete root;
            root = nullptr;
        }
    }
    
    void push(int x) {
        int cur;
        if(!root->prev)
            cur = x;
        else
            cur = ::min(root->m, x);
        MyNode *p = new MyNode(root, cur, x);
        root = p;
    }
    
    void pop() {
        MyNode *cur = root;
        root = root->prev;
        delete cur;
        cur = nullptr;
    }
    
    int top() {
        return root->val;
    }
    
    int min() {
        return root->m;
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