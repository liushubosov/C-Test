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


//迭代
// 暂时没写