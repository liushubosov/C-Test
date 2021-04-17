/*
* 232. 用栈实现队列
*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
 
说明：

你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

提示：

1 <= x <= 9
最多调用 100 次 push、pop、peek 和 empty
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）

* 
* 解题思路： 
*   
*/

class MyQueue {
private:
    stack<int> instack;
    stack<int> outstack;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {   
        int res;
        if(outstack.empty()){
            while(!instack.empty()){
                outstack.push(instack.top());
                instack.pop();
            }
        }
        res = outstack.top();
        outstack.pop();
        return res;
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
        return instack.empty()&&outstack.empty();
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