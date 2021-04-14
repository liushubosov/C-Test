/*
* 225. 用队列实现栈
*
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。
实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 
注意：

你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

提示：
    1 <= x <= 9
    最多调用100 次 push、pop、top 和 empty
    每次调用 pop 和 top 都保证栈不为空

* 
* 解题思路： 
*   
*/

class MyStack {
private:
    queue<int> myqueue;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = myqueue.size();
        myqueue.push(x);
        for(int i=0;i < n;++i){
            myqueue.push(myqueue.front());
            myqueue.pop();    
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = myqueue.front();
        myqueue.pop();
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return myqueue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myqueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */