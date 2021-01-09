/*
* 844. 比较含退格的字符串
*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

注意：
    1 <= S.length <= 200
    1 <= T.length <= 200
    S 和 T 只含有小写字母以及字符 '#'。
* 
* 解题思路： 
*   每个字符串分别用一个栈操作，比较栈的结果是否一致
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> mystack1;
        stack<char> mystack2;
        loadToStack(S, mystack1);
        loadToStack(T, mystack2);
        while(!mystack1.empty() && !mystack2.empty()){
            if(mystack1.top() != mystack2.top())
                return false;
            mystack1.pop();
            mystack2.pop();
        }
        return mystack1.empty() && mystack2.empty();
    }

    void loadToStack(const string &S, stack<char> &mystack){
        for(const auto &c:S){
            if(c == '#')
            {    
                if(!mystack.empty())
                    mystack.pop();
            }else        
                mystack.push(c);           
        }
    }
};