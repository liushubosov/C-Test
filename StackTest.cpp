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
};

int main()
{
	system("pause");
    return 0;
}

