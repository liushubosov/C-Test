/*
* 559. N叉树的最大深度
*
* 给定一个 N 叉树，找到其最大深度。
* 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
*
* 说明:
* 1. 树的深度不会超过 1000。
* 2. 树的节点总不会超过 5000。
* 
* 解题思路： 
*   深度优先遍历
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

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int deep = 0;
        for(int i=0;i < root->children.size();i++){
            deep = max(deep,maxDepth(root->children[i]));
        }
        return deep + 1;
    }
};