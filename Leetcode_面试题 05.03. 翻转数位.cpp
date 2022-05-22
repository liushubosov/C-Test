//面试题 05.03. 翻转数位
//给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。
 /*
解题思路
每次维护三个变量
cur：当前位置为止连续1的个数，遇到0归零，遇到1加1
insert：在当前位置变成1，往前数连续1的最大个数，遇到0变为cur+1，遇到1加1
res:保存insert的最大值即可

作者：sorrymaker-xz
链接：https://leetcode.cn/problems/reverse-bits-lcci/solution/dong-tai-gui-hua-zui-jian-ji-dai-ma-by-s-utws/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    int reverseBits(int num) {
       
        int curLen(0), seqLen(0), maxLen(0); 
        for(int i=0;i < 32;++i)
        {
            if((num&1) == 1)
            {
                ++curLen;
                ++seqLen;
            }
            else
            {
                seqLen = curLen + 1; 
                curLen = 0; 
            }
            maxLen = max(maxLen, seqLen);
            if(num == 0) break;
            num = (num >> 1);
        }
        return maxLen;
    }
};