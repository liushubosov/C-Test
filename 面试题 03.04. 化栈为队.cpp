/*
* 面试题 03.02. 栈的最小值
*
实现一个MyQueue类，该类用两个栈来实现一个队列。

示例：
你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
* 
* 解题思路： 
*   
*/

class MyQueue {
public:
    stack<int> instack;
    stack<int> outstack;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outstack.empty()){
            while(!instack.empty()){
                outstack.push(instack.top());
                instack.pop();
            }
        }
        int x = outstack.top();
        outstack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(outstack.empty()){
            while(!instack.empty()){
                outstack.push(instack.top());
                instack.pop();
            }
        }
        return outstack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return instack.empty() && outstack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */