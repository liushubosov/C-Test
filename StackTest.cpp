#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define abs(b) b<0?-b:b;

struct Point
{
	int x;
	int y;
	Point() {
		x = 0;
		y = 0;
	}

	Point(int a, int b) {
		x = a;
		y = b;
	}

};

// Definition for singly-linked list.
 struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		if (points.size() == 0)
			return 0;
		
		int nMax = 0;
		for (int i = 0; i < points.size(); i++)
		{
			map<float, int>  results;
			Point base = points[i];
			int nBase = 0;
			int nLineMax = 0;
			for (int j = i + 1; j < points.size(); j++)
			{
				if (points[j].y == base.y && points[j].x == base.x)
				{
					nBase++;
					continue;
				}
				float a = points[j].y - base.y;
				float b = points[j].x - base.x;
				float k = 0;
				if (b != 0)
					k = a / b;
				map<float, int>::iterator iter1;
				iter1 = results.find(k);
				// no key
				if (iter1 == results.end())
				{
					pair<float, int> value(k, 1);
					results.insert(value);
					if (nLineMax < 1)
						nLineMax = 1;
				}
				else
				{
					iter1->second++;
					if (iter1->second > nLineMax)
						nLineMax = iter1->second;
				}
			}
			nLineMax = nLineMax + 1 + nBase;
			if (nLineMax > nMax)
				nMax = nLineMax;
		}
		//nMax = nMax + 1 + nBase;
		return nMax;
	}


    //查找字符串数组中的最长公共前缀
    //如果不存在公共前缀，返回空字符串 ""
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size() == 0)
            return result;
        else if(strs.size() == 1)
            return strs[0];
        
        bool bFlag = false;
        string strBase = strs[0];
        for(int i=0;i < strBase.length();i++)
        {
            char cHead = strBase[i];
            for(int j=1;j < strs.size();j++)
            {
                if(strs[j][i] == cHead)
                    bFlag = true;
                else
                {
                    bFlag = false;
                    break;
                }
            }
            if(!bFlag)
                break;
            else
                result += cHead;
        }
        return result;
    }

	//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效
	bool isValid(string s) {
		if (s.empty())
			return true;
		stack<char> st;
		map<char, char> ma;
		ma['('] = ')';
		ma['['] = ']';
		ma['{'] = '}';
		map<char, char>::iterator iter;
        //第一个字符必须为左括号
        char cValue = s[0];
        iter = ma.find(cValue);
        if (iter == ma.end())
		{
			return false;
		}
        st.push(cValue);
        
		for (int i = 1; i < s.length(); i++)
		{
			cValue = s[i];           			
			if (st.empty())
				st.push(cValue);
			else
			{
				char cLast = st.top();
				//栈里不为空，当前字符又是左括号，继续压入栈
				iter = ma.find(cLast);
				if (iter != ma.end())
				{
					if (cValue == iter->second)
						st.pop();
					else
						st.push(cValue);
				}
				else
					return false;
			}
		}
        if (st.empty())
			return true;
		else
			return false;

	}

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* newp = new ListNode(0);
        ListNode* root = newp;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				newp->next = l1;
				l1 = l1->next;
			}
			else
			{
				newp->next = l2;
				l2 = l2->next;
			}
            newp = newp->next;
		}
		if (l1 != NULL)
		{
			newp->next = l1;
            newp = newp->next;
		}
		if (l2 != NULL)
		{
			newp->next = l2;
            newp = newp->next;
		}
		return root->next;
	}


//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
	int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i = 0;
        for(int j=1;j < nums.size();j++)
        {
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j]; 
            }
        }
             
        return i+1;
    }

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//你可以假设数组中无重复元素。
//此版本废弃
	int searchInsert_delete(vector<int>& nums, int target) {
        //二分查找
        int len = nums.size();
        if(len == 0)
            return 0;
        int nBlockLen = len;
        int medPos = nBlockLen / 2;
        bool bAdd = false;
               
        while(medPos >= 0 && nBlockLen > 0 )
        {                     
            int mLen = nBlockLen / 2;            
            if(nums[medPos] > target)
            {//left(nums[min,med],target)
                medPos -=  mLen;
                bAdd = false;
            }
            else if(nums[medPos] == target)
                return medPos; 
            else
            {//right(nums[med + 1,max],target)
                medPos += mLen;
                bAdd = true;
                if( medPos >= len)
                    medPos = len-1; 
            }          
            nBlockLen = mLen;
        }
        
        if (medPos < 0)
            medPos = 0;
        else if( medPos >= len)
            medPos = len-1;   
        if (bAdd)
			medPos++;
        return medPos;
    }

	int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for(i;i < nums.size();i++)
        {
            if(nums[i] >= target)
                return i;
        }
        return i;
    }

/**
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 */
	vector<int> plusOne(vector<int>& digits) {
        bool bNext = false;
        for(int i=digits.size()-1;i >= 0;i--)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
                bNext = true;
            }
            else
            {
                digits[i]++;
                bNext = false;
                break;
            }
            
        }
        if(bNext)
            digits.insert(digits.begin(),1);
        return digits;
    }

/**
 * 实现 strStr() 函数。
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 */
	int strStr(string haystack, string needle) {
        int pLen = needle.length();
        if(pLen == 0)
            return 0;        
        int tLen = haystack.length();
        if(tLen == 0)
            return -1;       
        if(tLen < pLen)
            return -1;
        else if(haystack == needle)
            return 0;
        
        for(int i=0;i < tLen - pLen + 1;i++)
        {
            if(haystack.substr(i,pLen) == needle)
                return i;
        }      
        return -1;
    }

/**给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* root = new ListNode(0);
        ListNode* p = root;
        int d = 0;
        while(l1 || l2)
        {
            int sum = 0;           
            int x = l1 ? l1->val : 0;
			int y = l2 ? l2->val : 0;
			sum = x + y + d;         
           
            p->next = new ListNode(sum%10);
            p = p->next;
            d = sum/10;  
            if(l1)
                l1 = l1->next;            
            if(l2)
                l2 = l2->next;
        }
        
        if(d > 0)
            p->next = new ListNode(d);
        return root->next;
    }

	/**
	 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
	 */
	int maxSubArray(vector<int>& nums) {
        int nMax = nums[0];
        int result = nums[0];
        for(int i=1;i < nums.size();i++)
        {
            nMax = max(nums[i],nMax + nums[i]);
            result = max(result,nMax);
        }
        return result;
    }

	/**
	 * 给定一个二叉树，检查它是否是镜像对称的。
	 */
	bool isSymmetric(TreeNode* root) {
        
        return traverse(root,root);
    }
    
    bool traverse(TreeNode* p1, TreeNode* p2)
    {
        if(!p1 && !p2) return true;
        if(!p1 || !p2) return false;
        
        return (p1->val == p2->val) && traverse(p1->left,p2->right) 
            && traverse(p1->right,p2->left);
    }

	/**
	 * 119. 杨辉三角 II
	 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
	 */
	vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        result[0] = 1;
        for(int i=1;i < rowIndex + 1;i++)
        {
            for(int j=i;j >= 1;j--)
            {
                result[j] = result[j-1] + result[j];
            }                                    
        }
        return result;
    }

	/**
	 * 121. 买卖股票的最佳时机
	 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
	 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
	 * 注意你不能在买入股票前卖出股票。
	 */
	int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2) return 0;
        int maxP = INT_MIN;
        int buyPos = 0;
        for(int i=1;i < len;i++)
        {
            int curP = prices[i] - prices[buyPos];
            //找到最低价格的位置
            if(curP < 0 )
            {
                buyPos = i;
                continue;
            }
            maxP = max(curP,maxP);
        }            
        return max(maxP, 0);
    }


	/**
	 * 111. 二叉树的最小深度
	 * 给定一个二叉树，找出其最小深度。
	 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
	 * 说明: 叶子节点是指没有子节点的节点。
	 */
	int minDepth(TreeNode* root) {
        if(!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);   
        if(l == 0 && r ==0) return 1;
        if(l == 0 || r ==0) return max(l,r)+1;
        return min(l,r) + 1;
    }


	/**
	 * 137. 只出现一次的数字 II
	 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
	 * 说明： 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
	 */
	int singleNumber(vector<int>& nums) {
        int a = 0,b = 0;
        //x & ~0 = x ; x & ~x = 0;  
        for(int i=0;i < nums.size();i++)
        {
            a = (a^nums[i]) & ~b;
            b = (b^nums[i]) & ~a;                  
        }
        return a;
    }

	/**
	 * 169. 求众数
	 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
	 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
	 * Boyer-Moore 投票算法
	 */
	int majorityElement(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for(int i=0;i < nums.size();i++)
        {
            if(count == 0)
                res = nums[i];
            if(res == nums[i])
                count++;
            else
                count--;
        }
        return res;
    }

};

int main()
{
	system("pause");
    return 0;
}

