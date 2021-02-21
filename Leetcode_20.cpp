/*
* 20. 有效的括号
*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true

提示：
1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成

* 
* 解题思路： 
*   使用栈
*/

class Solution {
public:
    bool isValid(string s) {
		stack<char> st;
		unordered_map<char, char> ma;
		ma['('] = ')';
		ma['['] = ']';
		ma['{'] = '}';
          
		for (int i = 0; i < s.length(); ++i)
		{
			char cValue = s[i];           			
			if (st.empty())
				st.push(cValue);
			else
			{
				char cLast = st.top();
				//栈里不为空，当前字符又是左括号，继续压入栈
				auto iter = ma.find(cLast);
				if (iter != ma.end())
				{
					if (cValue == iter->second)
						st.pop();
					else
						st.push(cValue);
				}
				else
					return false;  //栈里只存左括号 
			}
		}
		return st.empty() == true;
	}
};