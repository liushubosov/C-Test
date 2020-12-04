/*
* 590. N叉树的后序遍历
*
* 给定一个 N 叉树，返回其节点值的后序遍历。
* 
* 说明: 递归法很简单，你可以使用迭代法完成此题吗?
*
* 
* 解题思路： 
*   后根遍历
*   第一种，递归
*   第二种，迭代
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//递归
class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {    
        dfs(root);
        return res;
    }

    void dfs(Node* p){
        if(!p)
            return;
        for(int i=0;i < p->children.size();i++){
            dfs(p->children[i]);
        }
        res.push_back(p->val);
    }
};


//迭代1
// 与先根迭代代码类似，只是往栈中存孩子节点的时候，不再从后往前存，改为从前往后存。
// 这是因为数组最后需要反转一下
class Solution2 {
public:    
    vector<int> postorder(Node* root) {            
        if(!root)
            return {};
        vector<int> res;
        stack<Node*> myStack;
        myStack.push(root);
        while(!myStack.empty()){
            Node* p = myStack.top();
            res.push_back(p->val);
            myStack.pop();
            for(int i=0;i < p->children.size();i++){
                myStack.push(p->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//迭代2
// 破坏了原结构（把节点的孩子节点全清空了），不推荐
class Solution {
public:    
    vector<int> postorder(Node* root) {            
        if(!root)
            return {};
        vector<int> res;
        stack<Node*> myStack;
        myStack.push(root);
        while(!myStack.empty()){
            Node* p = myStack.top();
            if(p->children.size() == 0){
                res.push_back(p->val);
                myStack.pop();
            }else{
                for(int i=p->children.size()-1;i>=0 ;i--){
                    myStack.push(p->children[i]);
                }
                p->children.clear();
            }
        }
        return res;
    }
};