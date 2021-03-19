/*
* 119. 杨辉三角 II
*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

* 
* 解题思路： 
*   使用滚动数组
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        result[0] = 1;
        for(int i=1;i <= rowIndex;++i)
        {
            for(int j=i;j > 0;--j)
                result[j] += result[j-1];                                
        }
        return result;
    }
};