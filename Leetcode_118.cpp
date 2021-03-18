/*
* 118. 杨辉三角
*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

* 
* 解题思路： 
*   
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i=0;i < numRows;++i)
        {
            for(int j=0;j <= i;++j)
            {
                if(j == 0 || j == i)
                    result[i].push_back(1);
                else
                    result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            }
        }
        return result;
    }
};