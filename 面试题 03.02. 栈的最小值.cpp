/*
* 面试题 03.02. 栈的最小值
*
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。

* 
* 解题思路： 
*   二叉树没有顺序，必须全部
*/

struct MyNode{
    int min;
    int val;
    MyNode *prev;
    MyNode():prev(nullptr){};
    MyNode(int m, int v, MyNode *p):min(m), val(v), prev(p){};
};
class MinStack {
public:
    MyNode *root;
    /** initialize your data structure here. */
    MinStack() {
        root = new MyNode();
    }
    
    void push(int x) {
        int curmin;
        if(!root->prev)
            curmin = x;
        else{
            curmin = min(root->min, x);
        }
        MyNode *node = new MyNode(curmin, x, root);
        root = node;
    }
    
    void pop() {
        MyNode *tmp = root;
        root = root->prev;
        delete tmp;
        tmp = nullptr;
    }
    
    int top() {
        return root->val;
    }
    
    int getMin() {
        return root->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */